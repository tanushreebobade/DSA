class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int sum = 0 , maxi = INT_MIN;
      int i = 0;
      while( i < nums.size()){
        sum += nums[i];
        maxi = max(sum, maxi);
        if(sum < 0 ) sum = 0;
        i++;
      }
      return maxi;

    }
};