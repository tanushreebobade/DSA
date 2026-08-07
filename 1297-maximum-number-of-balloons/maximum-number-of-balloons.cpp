class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string s = "balloon";
        unordered_map<char,int>mp;
        unordered_map<char,int>mp2;
        int ans = INT_MAX;
        for(auto it :text){
            mp[it]++;
        }

        for(auto it : s){
            mp2[it]++;
            
        }
        for(auto it : mp2){
            ans = min(ans, mp[it.first]/it.second);
        }
        return ans;
    }
};