class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(auto it: s){
            mp[it]++;
        }
        int ans = 0;
        bool odd = false;

        for( auto it :mp){

            if(mp[it.first] % 2 == 0){
                ans = ans + mp[it.first];
            }
            else {
               ans += it.second -1;
               odd = true;
            }
        }
        if(odd)ans++;
        return ans;
    }
};