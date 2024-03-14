// class Solution {
// public:
//     int startPos(vector<int>& nums, int target){
        
//         int n = nums.size();
//        // int startInd = 0;
//         int l = 0;
//         int r = n-1;
        
//         while(l < r){
//             int mid = l+(r-l)/2;
            
//             if(nums[mid] < target){
                
//                 l = mid+1;
//             }else{
//                 r = mid;
//             }
//         }
        
//         return (nums[l]==target) ? l : -1 ;
//     }
//     int endPos(vector<int>& nums, int target){
        
//         int n = nums.size();
//        // int startInd = 0;
//         int l = 0;
//         int r = n-1;
        
//         while(l < r){
//             int mid = l+(r-l)/2;
            
//             if(nums[mid] > target){
                
//                 r = mid-1;
//             }else{
//                 l = mid;
//             }
//         }
        
//         return (nums[r]==target) ? r : -1;
//     }
    
    
//     vector<int> searchRange(vector<int>& nums, int target) {
        
//         vector<int> ans;
        
//        int start = startPos(nums,target);
//         ans.push_back(start);
//         int end  = endPos(nums,target);
//         ans.push_back(end);
//         return ans;
//     }
// };
class Solution {
public:
    int find_first_position(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int result = -1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target) {
                result = mid; //possibly my answer
                r = mid-1;     //but lets look at left more
            } else if(nums[mid] > target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return result;
    }
    
    int find_last_position(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int result = -1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target) {
                result = mid; //possibly my answer
                l = mid+1;   //but lets look at right more
            } else if(nums[mid] > target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return result;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int l = find_first_position(nums, target);
        int r = find_last_position(nums, target);
        
        return {l, r};
    }
};
