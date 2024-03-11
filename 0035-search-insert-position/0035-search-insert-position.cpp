class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        if(target > nums[n-1]){
            return n;
        }
        
        int l = 0;
        int r = n-1;
        
        while( l < r){
            
            int mid = (l+r)/2;
            
            if(nums[mid]==target){
                return mid;
            }
            
            if(nums[mid] < target){
                l = mid+1;
            }else{
                r = mid;
            }
            
        }
        
        return r;
    }
};