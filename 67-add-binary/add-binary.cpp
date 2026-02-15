class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        string res = "";
        while (i >= 0 || j >= 0 || carry) {
            int total = carry;
            if (i >= 0) {
                total += (a[i] - '0');
                i--;
            }
            if (j >= 0) {
                total += (b[j] - '0');
                j--;
            }
            res += char((total % 2) + '0');
            carry = total / 2;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
