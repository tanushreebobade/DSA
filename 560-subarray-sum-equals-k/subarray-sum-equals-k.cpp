class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<long long,int> freq; 
        freq[0] = 1;                      
        long long sum = 0;
        int count = 0;
        for (int x : nums) {
            sum += x;
            long long need = sum - k;
            if (auto it = freq.find(need); it != freq.end()) {
                count += it->second;
            }
            freq[sum]++; 
        }
        return count;
        
    }
};