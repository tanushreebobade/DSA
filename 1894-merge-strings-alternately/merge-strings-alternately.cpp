class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        string s = "";

        // ek ek char dono string se lena hai
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (i < n)
                s += word1[i];
            i++;
            if (j < m)
                s += word2[j];
            j++;
        }

        while (i < n) {
            s += word1[i];
            i++;
        }
        while (j < m) {
            if (j < m)
                s += word2[j];
            j++;
        }

        return s;
    }
};