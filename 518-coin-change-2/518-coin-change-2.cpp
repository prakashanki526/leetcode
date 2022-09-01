class Solution {
public:
    long f(int amount, vector<int> &coins, int n, vector<vector<int>>&dp){
        if(n==0){
            if(amount%coins[0]==0)
                return dp[n][amount]= 1;
            return 0;
        }
        if(dp[n][amount]!=-1)
            return dp[n][amount];
        long np = f(amount,coins,n-1,dp);
        long p=0;
        if(coins[n]<=amount)
            p = f(amount-coins[n],coins,n,dp);
        return dp[n][amount]=p+np;
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return f(amount,coins,coins.size()-1,dp);
    }
};