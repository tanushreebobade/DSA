class Solution {
public:
    bool wordPattern(string pattern, string s) {

        unordered_map<char, string> p; // a->dog
        unordered_map<string, char> st; //dog->a

        // stringstream sentence ko ek-ek word mein read karega
        string word;
        stringstream ss(s);

        for (int i = 0; i < pattern.size(); i++) {

            if (!(ss >> word))
                return false;

            if (p.count(pattern[i]) && p[pattern[i]] != word)
                return false;

            if (st.count(word) && st[word] != pattern[i])
                return false;

            p[pattern[i]] = word;
            st[word] = pattern[i];
        }

        // extra words b
        if (ss >> word)
            return false;

        return true;
    }
};