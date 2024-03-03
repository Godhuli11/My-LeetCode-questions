class Solution {
public:
     int coinChangeRecursiveHelper(const vector<int>& coins, int amount,vector<int> &dp) {
        if (amount == 0) {
            return 0;
        }
          
        if(dp[amount]!=-1) return dp[amount];
        int minCoins = INT_MAX;

        for (int coin : coins) {
            if (coin <= amount) {
                int subproblem = coinChangeRecursiveHelper(coins, amount - coin,dp);
                if (subproblem != INT_MAX) {
                    minCoins = min(minCoins, 1 + subproblem);
                }
            }
        }
         dp[amount] = minCoins;
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
           int result = coinChangeRecursiveHelper(coins, amount,dp);
        return (result == INT_MAX) ? -1 : result;
    }
};