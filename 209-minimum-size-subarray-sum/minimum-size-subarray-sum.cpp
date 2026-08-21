class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int  n = nums.size();
       // i
      //  j
        //2 3 1 2 4 3   t = 7
        int i = 0 , j = 0;
        int sum = 0;
        int ans = INT_MAX;
        while(j < n){


            sum+= nums[j];

            while( sum >= target){
                ans = min(ans, j-i+1);

                sum-=nums[i];
                i++;

            }
            j++;


        }

        return ans == INT_MAX?0:ans;
    }
};