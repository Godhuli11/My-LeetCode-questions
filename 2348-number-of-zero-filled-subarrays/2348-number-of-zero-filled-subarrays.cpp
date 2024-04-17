class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        int n = nums.size();
        
        int i=0;
        
        long  long res = 0;
        
        while(i<n){
            long long l = 0;
            
            if(nums[i]==0){
                 
                while(i<n && nums[i]==0){
                l++;
                i++;
            }
            
            }else{
                i++;
            }
           
            res += l*(l+1)/2;
            
        }
        
        return res;
    }
};
