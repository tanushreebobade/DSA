class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int it = 0; it < nums.size(); it++) {
            int req = target - nums[it];
            if (mp.find(req) != mp.end())
                return {mp[req], it};

            mp[nums[it]] = it;
        }
        return {-1, -1};
    }
};