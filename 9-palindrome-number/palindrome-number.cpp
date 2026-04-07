
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int original = x;
        string s = std::to_string(x);
        string r = s;
         reverse(s.begin(),s.end());
        if (s == r){
        return true;
        }
        return false;

    }
};