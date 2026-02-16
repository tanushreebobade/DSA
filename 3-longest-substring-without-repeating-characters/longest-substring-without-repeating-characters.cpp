class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window
        int n = s.size();
        int maxlen = 0;
        if (n == 0)
            return 0;
        int hash[256];
        for (int i = 0; i < 256; i++)
            hash[i] = -1;
        int l = 0, r = 0;
       
        while (r < n) {
            if (hash[s[r]] != -1) {
                if (hash[s[r]] >= l) {
                    l = hash[s[r]] + 1;
                }
            }
            int len = r - l + 1;
            maxlen = max(maxlen, len);
            hash[s[r]] = r;
            r++;
        }

        return maxlen;
    }
};