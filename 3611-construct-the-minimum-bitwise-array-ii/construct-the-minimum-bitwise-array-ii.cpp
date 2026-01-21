class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int n : nums) {
            if (n == 2) {
                ans.push_back(-1);
                continue;
            }
            int found = -1;
            for (int p = 1; p < 32; ++p) {
                if ((n >> p & 1) == 0) {
                    found = n ^ (1 << (p - 1));
                    break;
                }
            }
            ans.push_back(found);
        }
        return ans;
    }
};
