class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int l = 0;
        int r = nums.size()-1;
        
        while(l < r){
            int temp = nums[l]+nums[r];
            if(temp > target){
                r--;
            }else if(temp < target){
                l++;
            }else{
                break;
            }
        }
        
        return {l+1,r+1};
    }
};