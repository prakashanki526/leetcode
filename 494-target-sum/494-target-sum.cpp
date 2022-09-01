class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        
        if((sum-target)%2!=0 || target>sum)
            return 0;
        int k = (sum-target)/2, n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
        // if(k>=nums[0])
        //     dp[0][nums[0]]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                int np = dp[i-1][j];
                int p=0;
                if(nums[i-1]<=j)
                    p=dp[i-1][j-nums[i-1]];
                dp[i][j]=p+np;
            }
        }
        return dp[n][k];
    }
};