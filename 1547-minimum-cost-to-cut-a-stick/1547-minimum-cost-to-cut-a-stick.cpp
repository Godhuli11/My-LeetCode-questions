// class Solution {
// public:
//     int solve(int l , int r , vector<int> &cuts , vector<vector<int>> dp){
        
//         if(r-l < 2){
//             return 0;
//         }
        
//         if(dp[l][r]!=-1) return dp[l][r];
        
//         int ans = INT_MAX;
        
//         for(int i=l+1 ; i<=r-1 ; i++){
//             int cost = cuts[r]-cuts[l] + solve(l,i,cuts,dp)+solve(i,r,cuts,dp);
            
//             ans = min(ans,cost);
//         }
        
//         return dp[l][r]=ans;
        
//     }
//     int minCost(int n, vector<int>& cuts) {
        
//         sort(cuts.begin(),cuts.end());
        
//         cuts.insert(cuts.begin(),0);
        
//         cuts.push_back(n);
        
//         vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
//         return solve(0,cuts.size()-1,cuts,dp);
//     }
// };
class Solution {
public:
    int solve(int l, int r, vector<int>& cuts, vector<vector<int>>& dp) {
        if (r - l < 2) {
            return 0;
        }

        if (dp[l][r] != -1) {
            return dp[l][r];
        }

        int ans = INT_MAX;

        for (int i = l + 1; i <= r - 1; i++) {
            int cost = cuts[r] - cuts[l] + solve(l, i, cuts, dp) + solve(i, r, cuts, dp);
            ans = min(ans, cost);
        }

        return dp[l][r] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), -1));

        return solve(0, cuts.size() - 1, cuts, dp);
    }
};