class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int minA = INT_MAX, cntNeg = 0;
        for (auto& row : matrix) {
            for (int x : row) {
                minA = min(minA, abs(x));
                if (x < 0) {
                    sum -= x;
                    cntNeg++;
                } else {
                    sum += x;
                }
            }
        }
        return (cntNeg & 1) ? sum - 2 * minA : sum;
    }
};