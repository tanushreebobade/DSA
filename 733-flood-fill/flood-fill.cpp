class Solution {
public:
    void dfs(vector<vector<int>> image, int row, int col, int color,
             vector<vector<int>>& ans, int starting_color) {
        int n = image.size();
        int m = image[0].size();
        ans[row][col] = color;
        int delrow[] = {0, -1, 0, 1};
        int delcol[] = {-1, 0, 1, 0};
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                image[nrow][ncol] == starting_color && ans[nrow][ncol] != color) {
                ans[nrow][ncol] = color;
                dfs(image, nrow, ncol, color, ans, starting_color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        vector<vector<int>> ans = image;
        int starting_color = image[sr][sc];
        dfs(image, sr, sc, color, ans, starting_color);
        return ans;
    }
};