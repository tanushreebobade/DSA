class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxpro= nums[0];
        int minpro= nums[0];
        int ans = nums[0];
        for(int i = 1 ; i < nums.size(); i++){
            int tempmax = max({nums[i], nums[i]*maxpro,nums[i]*minpro});
            int tempmin = min({nums[i], nums[i]*maxpro,nums[i]*minpro});
            maxpro= tempmax;
            minpro= tempmin;

            ans= max(ans,maxpro);
        }
        return ans;
    }
};