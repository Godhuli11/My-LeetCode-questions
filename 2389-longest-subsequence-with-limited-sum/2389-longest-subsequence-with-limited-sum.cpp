class Solution {
public:
    int bs(vector<int>& nums , int query , int n){
        int l = 0;
        int r = n-1;
        int res = -1;
        while(l<=r){
            
          int  mid = l + (r-l)/2;
           
            
            if(nums[mid]<=query){
                res = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
            
        }
        return res+1;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        
        vector<int> ans;
        
        for(int i=1; i<n ; i++){
            nums[i] += nums[i-1];
        }
        
        for(auto &query :  queries){
            int count = bs(nums,query,n);
            ans.push_back(count);
        }
        return ans;
    }
};