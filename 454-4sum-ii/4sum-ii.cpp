class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {
        unordered_map<int, int> mp;
        int ans = 0;

        for (auto a : nums1) {
            for (auto b : nums2) {
                mp[a + b]++;
            }
        }
        for (int c : nums3) {
            for (int d : nums4) {
                int sum = c + d;

                if (mp.count(-sum))
                    ans += mp[-sum];
            }
        }

        return ans;
    }
};