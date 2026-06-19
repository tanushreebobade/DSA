class Solution {
private:
    void dfs(vector<vector<int>> image, vector<vector<int>>& ans, int row,
             int col, int color, int ini_color) {
        int n = image.size();
        int m = image[0].size();
        ans[row][col] = color;
       int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int n_row = del_row[i] + row;
            int n_col = del_col[i] + col;
            if (n_row >= 0 && n_row < n && n_col >= 0 && n_col < m &&
                ans[n_row][n_col] == ini_color && ans[n_row][n_col] != color) {
                ans[n_row][n_col] = color;
                dfs(image, ans, n_row, n_col, color, ini_color);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        vector<vector<int>> ans = image;
        int ini_color = image[sr][sc];

        dfs(image, ans, sr, sc, color, ini_color);
        return ans;
    }
};