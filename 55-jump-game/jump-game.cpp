class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxj = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if( i > maxj)return false;
            maxj = max(maxj,  nums[i] + i);
        }
        return true;
    }
};