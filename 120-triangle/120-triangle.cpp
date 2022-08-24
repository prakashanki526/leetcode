class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle.size()));
        
        dp[0][0]=triangle[0][0];
        
        for(int i=1;i<triangle.size();i++)
            dp[i][0]=triangle[i][0]+dp[i-1][0];
        
        for(int i=1;i<triangle.size();i++){
            for(int j=1;j<=i;j++){
                if(j!=i)
                dp[i][j]=triangle[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
                else
                    dp[i][j]=triangle[i][j]+dp[i-1][j-1];
            }
        }
        // int res= *min_element(dp[triangle.size()-1].begin(),dp[triangle.size()-1].end());
        int res=INT_MAX;
        for(int i=0;i<triangle.size();i++)
            res=min(res,dp[triangle.size()-1][i]);
        return res;
    }
};