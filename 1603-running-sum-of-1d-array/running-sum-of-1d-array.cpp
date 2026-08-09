class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans;
        int sum = nums[0];
        ans.push_back(sum);
        for(int i = 1 ; i < nums.size();i++){
          int rsum = ans[i-1]+ nums[i];
          ans.push_back(rsum);
        }
        return ans;
    }
};