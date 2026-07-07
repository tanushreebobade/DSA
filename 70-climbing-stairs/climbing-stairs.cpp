class Solution {
public:
    // int climb( int n, vector<int>&dp){
    //     if(n <= 2){
    //         return n;
    //     }
    //     if( dp[n] != -1){
    //         return dp[n];
    //     }
    //      return dp[n] = climb(n-1,dp) +climb(n-2,dp);
    // }

    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        // bottom up: tabulationn ny looking at base case of topp down app..
        //  vector<int>dp(n+1,-1);
        //  dp[0]= 0;
        //  dp[1]= 1;
        //  dp[2]= 2;
        //  for(int i =3; i <=n; i++ ){
        //      dp[i] = dp[i-1]+dp[i-2];

        // }
        // space optimization
        vector<int> dp(3);

        dp[0] = 1;
        dp[1] = 2;
        for(int i = 3; i <= n ; i++){
            
            dp[2]= dp[0] +dp[1];
             dp[0] = dp[1];
            dp[1]=dp[2];
         
        }

        return dp[1];
    }
};