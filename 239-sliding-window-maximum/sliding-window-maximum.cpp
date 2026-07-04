class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>dq; // index store krenge 
          vector<int>result;

        for( int i = 0 ; i < n ; i++){
                // valid window size  i - k 
                while( !dq.empty() &&  dq.front() <=i - k){
                    //remove
                    dq.pop_front();
                }
                while( !dq.empty() && nums[ i ] >=  nums[dq.back()] ){

                    dq.pop_back();
                }
                dq.push_back(i);

                if( i >= k - 1 ){
                    result.push_back( nums[dq.front()]);
                }
//o(N)
        }
        return result;
    
    }
};