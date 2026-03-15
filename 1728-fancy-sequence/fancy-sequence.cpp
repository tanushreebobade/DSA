class Fancy {
public:
    const long mod = 1e9+7;
    vector<long long> arr;
    long long mul = 1;
    long long add = 0;

    long long modInverse(long long x){
        long long res = 1, power = mod-2;
        x %= mod;
        while(power){
            if(power & 1) res = (res * x) % mod;
            x = (x * x) % mod;
            power >>= 1;
        }
        return res;
    }

    Fancy() {}

    void append(int val) {
        long long stored = ((val - add + mod) % mod * modInverse(mul)) % mod;
        arr.push_back(stored);
    }

    void addAll(int inc) {
        add = (add + inc) % mod;
    }

    void multAll(int m) {
        mul = (mul * m) % mod;
        add = (add * m) % mod;
    }

    int getIndex(int idx) {
        if(idx >= arr.size()) return -1;
        return (arr[idx] * mul % mod + add) % mod;
    }
};