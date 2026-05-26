class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        for(int i = 0; i < nums.size(); i++){
            int number = target - nums[i];
            if(mpp.find(number) != mpp.end()){
                return {i,mpp[number]};

            }
            mpp[nums[i]]= i;
        }
        return {};
    }
};