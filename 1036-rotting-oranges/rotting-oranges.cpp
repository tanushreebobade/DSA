class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        int n = grid.size();
        int m = grid[0].size();
   vector<vector<int>> ans(n,vector<int>(m,0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j] ==2){
                q.push({{i, j}, 0});
                ans[i][j] = 2;
                }
                else{
                    ans[i][j] = 0;
                }
            }
        }
        int del_row[] = {-1, 0, 1, 0};
        int del_col[]= {0, 1, 0, -1};

        int time = 0;
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int n_row = r + del_row[i];
               int n_col = c + del_col[i];
                if (n_row >= 0 && n_row < n && n_col >= 0 && n_col  < m &&
                    grid[n_row][n_col] == 1 && ans[n_row][n_col] == 0) {
                        q.push({{n_row,n_col},t +1});
                        ans[n_row][n_col] =2;

                }
                time = max(time, t);

            }
        }
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < m; j++){
                if( ans[i][j] != 2 && grid[i][j] ==1){
                    return -1;
                }
            }
        }
        return time;
    }
};