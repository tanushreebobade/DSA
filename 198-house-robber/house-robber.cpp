class Solution {
public:
    //     int maxAmt(int n, vector<int>& nums ,vector<int>&dp) {

    //     //top down
    //         if (n == 0) {
    //             return nums[0];
    //         }
    //         if (n == 1) {
    //             return max(nums[0], nums[1]);
    //         }
    //         if(dp[n] != -1){
    //             return dp[n];

    //         }

    //         return dp[n]= max(nums[n] + maxAmt(n - 2, nums,dp),
    //                    maxAmt(n - 1, nums ,dp));
    //     }/


    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) return nums[0];

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
