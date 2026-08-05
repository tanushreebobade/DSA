class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                cnt++;
                if (1LL * i * i  < n) {
                    for (int j = i * i; j < n; j += i) {
                        prime[j] = false;
                    }
                }
            }
        }
        return cnt;
    }
};