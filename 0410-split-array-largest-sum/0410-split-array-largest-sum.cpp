class Solution {
public:
    int countPartitions(vector<int>& nums, int maxSum){
        
        int partitions = 1;
        
        int subASum = 0;
        
        for(int i = 0 ; i<nums.size() ; i++){
            
            if( subASum + nums[i] <= maxSum){
                subASum += nums[i];
            }else{
                partitions++;
                subASum = nums[i];
            }
            
        }
        
        return partitions;
        
    }
    int splitArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        int low = INT_MIN;
        
        for(int i=0 ; i<n ; i++){
            low = max(nums[i],low);
        }
        
        int high = 0;
        
        for(int i=0 ; i<n ; i++){
            high += nums[i];
        }
        
        while(low < high ){
            
            int mid = (low + high) / 2;
            
            int partitions = countPartitions(nums,mid);
            
            if( partitions > k){
                low = mid + 1;
            }else{ //partitions <= k
                
                high = mid;
            }
        }
        
        return high;
    }
};