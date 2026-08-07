class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        
        unordered_map<char, int> mp2;
     
        for (auto it : magazine) {
            mp2[it]++;
        }

   
        for (auto it : ransomNote) {
            if(mp2[it] ==0){
                return false;
            }else{
                mp2[it]--;
            }
        }
        return true;
    }
};