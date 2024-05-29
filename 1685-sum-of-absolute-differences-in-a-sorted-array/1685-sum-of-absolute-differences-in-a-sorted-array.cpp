class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> result(n);
        
        vector<int> prefix(n);
        
         prefix[0]=nums[0];
        
        for(int i=1 ; i<n ; i++){
            
            prefix[i] = prefix[i-1] + nums[i];
            
        }
        
       
        
        for(int i=0 ; i<n ; i++){
            
            
            int leftSum = 0;
            if(i>0){
                leftSum = prefix[i-1];
            }
            
            
            int rightSum = prefix[n-1] - prefix[i];
            
            result[i] = nums[i]*i - leftSum + rightSum - nums[i]*(n-i-1);
        }
        return result;
    }
};