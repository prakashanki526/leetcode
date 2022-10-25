class Solution {
public:
    int solve(vector<int>&p, int i, int buy, int n, vector<vector<int>>&dp){
        if(i==n)
            return 0;
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        int profit = 0;
        if(buy)
            return dp[i][buy] = max(solve(p,i+1,1,n,dp),-p[i]+solve(p,i+1,0,n,dp));
        else
            return dp[i][buy] = max(solve(p,i+1,0,n,dp),p[i]+solve(p,i+1,1,n,dp));
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices,0,1,n,dp);
    }
};