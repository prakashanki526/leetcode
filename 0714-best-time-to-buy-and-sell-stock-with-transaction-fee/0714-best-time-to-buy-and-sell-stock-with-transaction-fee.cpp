class Solution {
public:
    int solve(vector<int>&p, int i, int buy, int n, int fee, vector<vector<int>>&dp){
        if(i == n)
            return 0;
        if(dp[i][buy] != -1)
            return dp[i][buy];
        if(buy)
            return dp[i][buy] = max(solve(p,i+1,1,n,fee,dp),-p[i]+solve(p,i+1,0,n,fee,dp));
        else
            return dp[i][buy] = max(solve(p,i+1,0,n,fee,dp),p[i]-fee+solve(p,i+1,1,n,fee,dp));
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices,0,1,n,fee,dp);
    }
};