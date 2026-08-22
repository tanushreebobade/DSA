class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int i = 0, j = 0, maxi = 0, z = 0;

        while (j < nums.size()) {

            if (nums[j] == 0)
                z++;

            while (z > k) {
                if (nums[i] == 0)
                    z--;
                i++;
            }

            maxi = max(maxi, j - i + 1);

            j++;
        }

        return maxi;
    }
};