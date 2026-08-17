class Solution {
public:
    int compress(vector<char>& chars) {
        int r = 0 ;
        int w = 0;

        while( r < chars.size()){

            char curr = chars[r];
            int cnt = 0;

            while( r < chars.size() && chars[r] == curr){
                r++;
                cnt++;
            }
            chars[w++] = curr;

            if( cnt > 1){
                string s = to_string(cnt);
                
                for( char c:s){
                    chars[w++] =c;
                }
            }
        }

        return w;
    }
};