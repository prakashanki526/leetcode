class Solution {
public:
    int f = 0;
    int solve(string s, int n, int i, vector<int>&dp){
        if(i>=n)
            return 1;
        if(s[i]=='0')
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int op = solve(s,n,i+1,dp);
        int tp = 0;
        if(i+1<n && ((s[i]=='1' && s[i+1]<='9') || (s[i]=='2' && s[i+1]<'7')))
           tp = solve(s,n,i+2,dp);
        return dp[i]=op+tp;
    }
    int numDecodings(string s) {
        vector<int>dp(s.length(),-1);
        return solve(s,s.length(),0,dp);
    }
};