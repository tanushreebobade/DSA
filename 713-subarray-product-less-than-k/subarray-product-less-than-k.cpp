class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt = 0;
        if (k  <= 1) {
            return 0;
        }

        //[10,5,2,6]

        int i = 0, j = 0;
        int pro = 1;

        while (j < nums.size()) {
            pro *= nums[j];

            while (pro >= k) {
                // shrink
                pro /= nums[i];
                i++;
            }
            cnt += j - i + 1;
            j++;
        }
        return cnt;
    }
};