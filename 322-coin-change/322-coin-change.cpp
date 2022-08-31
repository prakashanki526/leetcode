class Solution {
public:
    int f(vector<int>&coins, int amount, int n, vector<vector<int>>&dp){
        // if(amount==0)
        //     return 0;
        if(n==0)
        {
            if(amount%coins[n]==0)
                return dp[n][amount]=amount/coins[n];
            return 1e9;
        }
        
        if(dp[n][amount]!=-1)
            return dp[n][amount];
        int np = f(coins,amount,n-1,dp);
        int p=INT_MAX;
        if(coins[n]<=amount)
            p = 1 + f(coins,amount-coins[n],n,dp);
        return dp[n][amount]=min(p,np);
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int res= f(coins, amount, coins.size()-1,dp);
        if(dp[coins.size()-1][amount]==1e9)
            return -1;
        return dp[coins.size()-1][amount];
    }
};