class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // a-1
        // b-1

        int k = s1.length();
        vector<int> freq(26, 0);

        for (auto ch : s1) {
            freq[ch - 'a']++;
        }

        vector<int> w(26, 0);
        int i = 0, j = 0;
        while (j < s2.length()) {

            // curr window ki freq
            w[s2[j] - 'a']++;

            if (j - i + 1 == k) {
                if (w == freq) {
                    return true;
                }
                w[s2[i] - 'a']--;
                i++;
            }
            j++;
        }

        return false;
    }
};