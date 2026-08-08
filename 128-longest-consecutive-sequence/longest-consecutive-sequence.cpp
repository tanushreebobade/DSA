class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        if (nums.size() == 0)
            return 0;

        for (auto it : nums) {
            st.insert(it);
        }

        int ans = 1;
        for (auto it : st) {
            if (st.count(it - 1))
                continue;

            int cnt = 1;
            while (st.count(it + 1)) {
                it++;
                cnt++;
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};