class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pref(n);
        int p = nums[0];
        pref[0]= 1;
        //prefix sum
        for(int i = 1 ; i < n ; i++){
            pref[i]=p;
            p*= nums[i];
        }

        p = nums[n-1];
        for(int i = n-2; i>=0 ;i--){
            pref[i]*=p;
            p*=nums[i];
        }

        return pref;
    }
};