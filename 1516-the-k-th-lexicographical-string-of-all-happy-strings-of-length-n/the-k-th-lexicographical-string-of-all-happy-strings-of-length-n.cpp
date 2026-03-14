class Solution {
public:
    
    void solve(int n, string curr, vector<string>& ans){
        
        if(curr.size() == n){
            ans.push_back(curr);
            return;
        }
        
        for(char ch : {'a','b','c'}){
            
            if(curr.empty() || curr.back() != ch){
                solve(n, curr + ch, ans);
            }
        }
    }
    
    string getHappyString(int n, int k) {
        
        vector<string> ans;
        
        solve(n,"",ans);
        
        if(k > ans.size()) return "";
        
        return ans[k-1];
    }
};