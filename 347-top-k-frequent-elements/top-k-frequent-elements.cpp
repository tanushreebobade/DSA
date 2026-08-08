class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto it : nums){
            mp[it]++;
        }
        
        int cnt =0;
        vector<pair<int,int>> v;
        
        for(auto it :mp){
            v.push_back({it.second,it.first});
            //first -> number second -> freq
        }

        sort(v.rbegin(),v.rend());

        vector<int>ans;
        for(int i = 0 ; i < k ; i++){
            ans.push_back(v[i].second);
        }

        return ans;
        
    }
};