class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1e9));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int take = nums1[i] * nums2[j] + max(0, dp[i + 1][j + 1]);
                int skip1 = dp[i + 1][j];
                int skip2 = dp[i][j + 1];
                dp[i][j] = max({take, skip1, skip2});
            }
        }
        return dp[0][0];
    }
};
