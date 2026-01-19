#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        // Prefix sum matrix
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = mat[i - 1][j - 1]
                             + prefix[i - 1][j]
                             + prefix[i][j - 1]
                             - prefix[i - 1][j - 1];
            }
        }

        int low = 0, high = min(m, n);
        int ans = 0;

        // Binary Search
        while (low <= high) {
            int mid = (low + high) / 2;

            if (existsSquare(prefix, mid, threshold)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }

private:
    // Check for any square of size k exists with sum <= threshold
    bool existsSquare(vector<vector<int>>& prefix, int k, int threshold) {
        int m = prefix.size();
        int n = prefix[0].size();

        for (int i = k; i < m; i++) {
            for (int j = k; j < n; j++) {
                int sum = prefix[i][j]
                        - prefix[i - k][j]
                        - prefix[i][j - k]
                        + prefix[i - k][j - k];

                if (sum <= threshold)
                   return true;
            }
        }
        return false;
    }
};
