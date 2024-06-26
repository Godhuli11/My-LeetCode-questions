class Solution {
public:
    typedef long long ll;
    long long countAlternatingSubarrays(vector<int>& nums) {
        ll ans = 0;
        
        int n = nums.size();
        
        for(int i=0 ; i<n ;i++){
            int j=i;
            
            while(j+1 < n && nums[j]!=nums[j+1]){
                j++;
            }
            
            int len = j-i+1;
            
            ans += (ll)len*(len+1)/2;
            
            i=j;
        }
        
        return ans;
    }
};