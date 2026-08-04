class Solution {
public:
    int countPrimes(int n) {
        vector<bool>prime(n+1,true);
        int cnt = 0;
        for(int i = 2; i < n ; i++){
            if(prime[i]){
                cnt++;
                for(int j = i*2 ; j < n ; j+=i){
                    prime[j]= false;
                }
            }
        }
        return cnt;
    }
};