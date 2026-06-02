
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0, maxi=INT_MIN;
        int i=0;
        int n=nums.size();
        while(i<n){
            sum+=nums[i];
            maxi=max(maxi, sum);
            if(sum<0) sum=0;
            
            i++;
        }
        return maxi;
    }
};