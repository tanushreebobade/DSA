class Solution {
public:
    // The greedy idea is to place taller people first.
    // After that, when placing a person of height h, everyone already placed is >= h.
    // Therefore, that person can be easily insert at its correct people[1] position.

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        // people[i] contains (height, count)
        // sort by height descending, count ascending
        sort(people.begin(), people.end(), [&](auto &a, auto &b) {
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });

        // insert each person at index k
        vector<vector<int>> ans;
        for(auto &p: people) ans.insert(ans.begin() + p[1], p);
        return ans;
    }
};