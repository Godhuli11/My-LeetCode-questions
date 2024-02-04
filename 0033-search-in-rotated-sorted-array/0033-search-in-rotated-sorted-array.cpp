class Solution {
public:
    
int findPivot(vector<int>& nums, int n){
    int l=0;
    int r=n-1;
    while(l<r){
        int mid = (l+r)/2;
        if(nums[mid]>nums[r]){
            l=mid+1;
        }else{
            r=mid;
        }
    }
    return r;
}
int binarySearch(int l , int r , vector<int> nums , int target){
  
    
    while(l<=r){
        int mid = (l+r)/2;
        if(nums[mid]==target){
            return mid;
        }else if (nums[mid] < target){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    return -1;
}
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int pivot_idx = findPivot(nums,n);
        
        int idx = binarySearch(0,pivot_idx-1,nums,target);
        
        if(idx!=-1){
            return idx;
        }
        
        idx = binarySearch(pivot_idx,n-1,nums,target);
        
        return idx;
    }
};