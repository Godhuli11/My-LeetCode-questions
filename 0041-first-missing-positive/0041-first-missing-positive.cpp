class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        
        bool is1Present = false;
        
        for(int i=0 ; i<n ; i++){
            if(nums[i]==1){
                is1Present = true;
            }
            
            if(nums[i]<=0 || nums[i] > n){
                nums[i] = 1;
            }
        }
        
        if(!is1Present) return 1;
        
        
        for(int i=0 ; i<n ; i++){
            
            int val = abs(nums[i]);
            int idx = val - 1;
            
            if(nums[idx]<0){
                continue;
            }else{
                nums[idx] *= -1;
            }     
        }
        
        for(int i=0 ; i<n ; i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        
        return n+1;
    }
};