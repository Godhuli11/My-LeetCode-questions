class Solution {
public:
//     bool solve(int ind ,vector<int>& nums,int target , int n ,vector<vector<int>> dp){
//         if(target==0){
//             return 1;
//         }
//         if(target < 0){
//             return 0;
//         }
//         if(ind >= n ){
//             return 0;
//         }
//         if(dp[ind][target]!=-1) return dp[ind][target];
//         int take = solve(ind+1 , nums , target - nums[ind] , n,dp);
//         int notTake = solve(ind+1 , nums , target , n,dp);
        
//         dp[ind][target]= take || notTake ;
        
//         return dp[ind][target];
//     }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        
            
        for(int i=0 ; i<nums.size() ; i++){
            total += nums[i];
        }
        
        if(total % 2 == 0){
            // int target = total/2 ; 
            vector<vector<int>> dp(n+1 , vector<int>((total/2)+1,0));
            
            for(int i=0 ; i<=n ; i++){
                dp[i][0]=1;
            }
            
            for(int ind=n-1 ; ind>=0 ; ind--){
                for(int target=0 ; target <= total/2 ; target++){
                    bool take = false;
                    if(target >= nums[ind]){
                        take = dp[ind+1][target-nums[ind]];
                    }
                    
                    bool notTake = dp[ind+1][target];
                    
                    dp[ind][target] = take || notTake;
                }
            }
            
            
           return dp[0][total/2];
        }else{
            return false;
        }
    }
};