class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        deque<int> flipQue;
        
        int flipsFromPast = 0;
        
        int flips = 0;
        
        for(int i=0 ; i<n ; i++){
            if(i>=k){
                flipsFromPast -= flipQue.front();
               
                flipQue.pop_front();
            }
            
            if(flipsFromPast%2 == nums[i]){ //flipping condition
                
                if(i+k > n){
                    return -1;
                }
                
                flips++;
                flipQue.push_back(1);
                flipsFromPast++;
            }else{
                flipQue.push_back(0);
            }
        }
        
        return flips;
    }
};