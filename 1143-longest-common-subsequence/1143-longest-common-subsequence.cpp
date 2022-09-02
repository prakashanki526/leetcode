class Solution {
public:
    int f(string s1, string s2, int i1, int i2, vector<vector<int>>&dp){
        if(i1==0 || i2==0)
            return 0;
        if(dp[i1][i2]!=-1)
            return dp[i1][i2];
        if(s1[i1-1]==s2[i2-1])
            return dp[i1][i2]= 1 + f(s1,s2,i1-1,i2-1,dp);
        return dp[i1][i2]= max(f(s1,s2,i1-1,i2,dp),f(s1,s2,i1,i2-1,dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(),m=text2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        // return f(text1,text2,n,m,dp);
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
        
    }
};