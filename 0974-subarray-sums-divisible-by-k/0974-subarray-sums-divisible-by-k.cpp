class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int ans = 0;
        
        unordered_map<int,int> mpp;
        
        int sum = 0;
        
        mpp[0] = 1;
        
        for(int i=0 ; i<nums.size() ; i++){
            
            sum += nums[i];
            
            int rem = sum % k;
            
            if(rem < 0){
                rem += k;
            }
            
            if(mpp.find(rem) != mpp.end()){
                ans += mpp[rem];
                mpp[rem]++;
            }else{
                mpp[rem]=1;
            }
            
        }
        
        return ans;
        
    }
};