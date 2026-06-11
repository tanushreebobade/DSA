class Solution {
public:
    bool checkValidString(string s) {
        // range
        int maxi = 0, mini = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                maxi++;
                mini++;
            } else if (s[i] == ')') {
                maxi--;
                mini--;
            } else {
                //* mini >0 positive
                maxi += 1;
                mini -= 1;
            }
            if (mini < 0)
                mini = 0;
            if (maxi < 0)
                return false;
        }

        return (mini == 0);
    }
};