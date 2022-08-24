class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+2,INT_MAX));
        
        for(int i=1;i<m+1;i++)
            dp[1][i]=matrix[0][i-1];
        
        for(int i=2;i<n+1;i++)
            for(int j=1;j<m+1;j++)
                dp[i][j]=matrix[i-1][j-1]+min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]));
            

        return *min_element(dp[n].begin(),dp[n].end());
    }
};