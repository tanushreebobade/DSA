class Solution {
public:
    double solve(vector<vector<int>> &squares, double limit) {
        int n = squares.size();
        double area = 0;
        for(int i = 0; i < n; i++) {
            double y = squares[i][1];
            double l = squares[i][2];

            if(y + l <= limit) area += (l*l);
            else if(y < limit && y + l > limit) area += (l*(limit - y));
        }
        return area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();

        double low = INT_MAX, high = INT_MIN;
        double tot_area = 0;
        for(int i = 0; i < n; i++) {
            double y = squares[i][1];
            double l = squares[i][2];
            if(y < low) low = y;
            if(y+l > high) high = y + l;

            tot_area += (l*l);
        }
        double ans = 0.0;
        while(high - low > 1e-5) { 
            double mid = low + (double) (high - low) / 2.0;
            double below_area = solve(squares, mid);

            if(below_area < tot_area / 2.0) low = mid;
            else high = mid;
        }
        return low;
    }
};