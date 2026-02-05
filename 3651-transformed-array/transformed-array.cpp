class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            int num = nums[i];

            if(num > 0) {
                int jump = num;
                int idx = (i + jump) % n;
                ans[i] = nums[idx];
            }
            else if(num < 0) {
                int jump = abs(num) % n; 
                int idx = ((i - jump) + n) % n;
                ans[i] = nums[idx];
            }
            else ans[i] = nums[i];
        }

        return ans;
    }
};