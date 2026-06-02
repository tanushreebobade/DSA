class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int ans = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        // land -> water i
        for (int i = 0; i < n; i++) {
            // water -> land j

            for (int j = 0; j < m; j++) {
                int landfin = landStartTime[i] + landDuration[i];
                int finish1 =
                    max(landfin, waterStartTime[j]) + waterDuration[j];

                int waterfinish = waterStartTime[j] + waterDuration[j];
                int finish2 =
                    max(waterfinish, landStartTime[i]) + landDuration[i];

                ans = min(ans, min(finish1, finish2));
            }
        }
        return ans;
    }
};

// Time:O(n*m)
// Space:O(1)