class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0, ans = 0;
        int cnt[26] = {};

        for (int r = 0; r < s.size(); r++) {
            cnt[s[r] - 'a']++;

            while (cnt[s[r] - 'a'] > 2) {
                cnt[s[l] - 'a']--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};