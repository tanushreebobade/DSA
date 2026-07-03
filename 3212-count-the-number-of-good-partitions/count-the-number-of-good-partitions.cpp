class Solution {
public:
    int m = 1e9 + 7;
    int numberOfGoodPartitions(vector<int>& nums) {
        // { 1 2 1 3 4 }
        //   i
        int n = nums.size();

        unordered_map<int, int> lastindex;

        for (int i = 0; i < n; i++) {
            lastindex[nums[i]] = i;
        }

        int i = 0;
        int j = 0;
         j = max(j, lastindex[nums[0]]);
        int result = 1;

        while (i < n) {

            if (i > j) {
                result = (result * 2)% m;
            }
            j = max(j, lastindex[nums[i]]);
            i++;
        }

        return result;
    }
};