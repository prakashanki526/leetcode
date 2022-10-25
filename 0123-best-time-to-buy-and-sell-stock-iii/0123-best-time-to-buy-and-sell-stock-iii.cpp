class Solution {
public:
    int solve(vector<int>&p, int i, int buy, int n, int k, vector<vector<vector<int>>>&dp){
        if(i==n || k==0)
            return 0;
        if(dp[i][buy][k] != -1)
            return dp[i][buy][k];
        if(buy)
            return dp[i][buy][k] = max(solve(p,i+1,1,n,k,dp),-p[i]+solve(p,i+1,0,n,k,dp));
        else
            return dp[i][buy][k] = max(solve(p,i+1,0,n,k,dp),p[i]+solve(p,i+1,1,n,k-1,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,1,n,2,dp);
    }
};