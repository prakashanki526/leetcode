class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(),m=obstacleGrid[0].size();
        int dp[n][m];
        int f=0;
        for(int i=0;i<m;i++){
            if(f==1)
                dp[0][i]=0;
            else if(obstacleGrid[0][i]==1){
                dp[0][i]=0;
                f=1;
                }
            else
                dp[0][i]=1;
        }
        f=0;
        for(int i=0;i<n;i++){
            if(f==1)
                dp[i][0]=0;
            else if(obstacleGrid[i][0]==1){
                dp[i][0]=0;
                f=1;
                }
            else
                dp[i][0]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(obstacleGrid[i][j]==1)
                dp[i][j]=0;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};