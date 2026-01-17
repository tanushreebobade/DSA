class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long max_area = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                auto &top2 = topRight[j], &bottom2 = bottomLeft[j]; // rectangle 1
                auto &top1 = topRight[i], &bottom1 = bottomLeft[i]; // rectangle 2

                int x1 = min(top2[0], top1[0]);
                int y1 = min(top2[1], top1[1]);
                int x2 = max(bottom2[0], bottom1[0]); 
                int y2 = max(bottom2[1], bottom1[1]);

                if(x1 > x2 && y1 > y2) { 
                    int width = x1 - x2;
                    int height = y1 - y2;

                    int side = min(width, height);
                    max_area = max(max_area, 1LL * side * side);
                }
            }
        }

        return max_area;
    }
};