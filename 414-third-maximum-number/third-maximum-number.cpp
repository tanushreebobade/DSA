class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st;
        for (auto it : nums) {
            st.insert(it);
        }
        
        auto it = st.rbegin();
        if (st.size() < 3)
            return *it;

        int k = 3;

        while (--k)
            it++;

        return *it;
    }
};