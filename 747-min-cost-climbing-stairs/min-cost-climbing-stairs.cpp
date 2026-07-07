class Solution {
public:
    // int minCost(vector<int>& cost , int n,  vector<int>&dp){
    //     if( n <=1){
    //         return 0;
    //     }
    //     if(dp[n]!= -1){
    //         return dp[n];
    //     }
    //     return dp[n] =min( minCost(cost,n-1,dp) +cost[n-1] ,
    //     minCost(cost,n-2,dp) +cost[n-2]);
    // }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(3);
        // bottom up
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[2] = min(dp[1] + cost[i - 1], dp[0] + cost[i - 2]);

            dp[0] = dp[1];
            dp[1] = dp[2];
        }

        return dp[1];
    }
};