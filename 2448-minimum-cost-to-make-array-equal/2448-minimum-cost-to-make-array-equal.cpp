class Solution {
public:
    typedef long long ll;
    
    ll findCost(vector<int>& nums, vector<int>& cost , int mid){
        
        ll val=0;
        
        for(int i=0 ; i<cost.size() ; i++){
            val += (ll) abs(mid - nums[i]) * cost[i]; 
        }
        
        return val;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        ll l = *min_element(nums.begin(),nums.end());
        ll r = *max_element(nums.begin(),nums.end());
        
        ll ans = INT_MAX;
        
        while(l <= r){
            
            int mid = l + (r-l)/2;
            
            ll cost1 = findCost(nums,cost,mid);
            ll cost2 = findCost(nums,cost,mid+1);
            
            ans = min(cost1 , cost2);
            
            if(cost1 < cost2){
                r = mid - 1;
            }else{
                l = mid+1;
            }
        }
        
        return (ans == INT_MAX) ? 0 : ans;
    }
};