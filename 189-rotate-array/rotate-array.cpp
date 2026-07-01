class Solution {
public:
    void reversearr(vector<int>& nums, int start, int end) {
        while (start < end) {
              swap(nums[start++], nums[end--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reversearr(nums, 0, n - k - 1);
        reversearr(nums, n - k, n - 1);
        reversearr(nums, 0, n - 1);
    }
};