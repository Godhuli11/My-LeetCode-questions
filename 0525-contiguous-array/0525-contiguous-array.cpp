class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int> mp;
        mp[0] = -1;
        
        int currSum = 0;
        
        int res = 0;
        
        for(int i=0 ; i<n ; i++){
            
            currSum += (nums[i] == 1) ? 1 : -1;
            
            if(mp.find(currSum) != mp.end()){
                res = max(res,i-mp[currSum]);
            }else{
                mp[currSum] = i;
            }
        }
        
        return res;
    }
};