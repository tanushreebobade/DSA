class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string t = s + s;
        int diff1 = 0, diff2 = 0;
        int ans = INT_MAX;
        int left = 0;
        for (int right = 0; right < t.size(); right++) {

            char p1 = (right % 2) ? '1' : '0';
            char p2 = (right % 2) ? '0' : '1';

            if (t[right] != p1)
                diff1++;
            if (t[right] != p2)
                diff2++;
            if (right - left + 1 > n) {
                char lp1 = (left % 2) ? '1' : '0';
                char lp2 = (left % 2) ? '0' : '1';

                if (t[left] != lp1)
                    diff1--;
                if (t[left] != lp2)
                    diff2--;

                left++;
            }

            if (right - left + 1 == n) {
                ans = min(ans, min(diff1, diff2));
            }
        }
        return ans;
    }
};