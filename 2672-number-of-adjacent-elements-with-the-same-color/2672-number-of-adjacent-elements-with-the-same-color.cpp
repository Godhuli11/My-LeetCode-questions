class Solution {
public:
 vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
      
        int count = 0;
        
        vector<int> nums(n,0), result;
        
        for(auto &q: queries) {
            
            int idx = q[0], val = q[1];
            
            if(idx > 0) {
                if(nums[idx-1] == 0);//don't do anything
                else if(nums[idx] == nums[idx-1]) {
                    if(nums[idx] != val)if(count > 0)count--;
                }
                else {
                    if(val == nums[idx-1])count++;
                }
            }
			
            if(idx+1 < n) {
                if(nums[idx+1] == 0);//don't do anything
                else if(nums[idx] == nums[idx+1]) {
                    if(nums[idx] != val)if(count > 0)count--;
                }
                else {
                    if(val == nums[idx+1])count++;
                }
            }
            
            nums[idx] = val;
            result.push_back(count);
        }
        
        return result;
    }
};