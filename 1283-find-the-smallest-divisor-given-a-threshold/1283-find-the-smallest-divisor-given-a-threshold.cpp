class Solution {
public:
//     bool isTrue(vector<int>& nums, int threshold,int divisor){
        
//         int sum=0;
        
//         for(int i=0 ; i<nums.size() ; i++){
            
//              double temp =(double) (nums[i]/divisor);
            
//              sum += ceil(temp);
//         }
        
//         return (sum<=threshold) ;
        
//     }
//     bool isTrue(vector<int>& nums, int threshold, int divisor) {
//     double sum = 0; // Use double for floating-point precision
    
//     for (int i = 0; i < nums.size(); i++) {
//         // Convert one operand to double to perform floating-point division
//         sum += ceil(static_cast<double>(nums[i]) / divisor);
//     }
    
//     return (sum <= threshold);
// }
    bool isTrue(vector<int>& nums, int threshold, int divisor) {
    int sum = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        sum += ceil((double)nums[i]/(double)divisor); // Calculate division result without rounding
    }
    
    return (sum <= threshold);
}

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        
        int high = INT_MIN;
        
        int n = nums.size();
        
        if(n>threshold) return -1;
        
        int ans = 0;
        
        for(int i=0 ; i<n ; i++){
            high = max(high , nums[i]);
        }
            
        while(low <= high){
            int mid = low+(high-low)/2;
            
            if(isTrue(nums,threshold,mid)){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        return low;
    }
};