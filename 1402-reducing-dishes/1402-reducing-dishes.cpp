class Solution {
public:
    int solve(vector<int>&v, int n, int i, int ind, vector<vector<int>>&dp){
        if(i==n)
            return 0;
        if(dp[i][ind] != -1e9)
            return dp[i][ind];
        int np = solve(v,n,i+1,ind,dp);
        int p = v[i]*ind + solve(v,n,i+1,ind+1,dp);
        
        return dp[i][ind] = max(p,np);
        
    }
    int maxSatisfaction(vector<int>& sat) {
        int n = sat.size();
        sort(sat.begin(),sat.end());
        vector<vector<int>>dp(n,vector<int>(n+1,-1e9));
        return solve(sat,n,0,1,dp);
    }
};