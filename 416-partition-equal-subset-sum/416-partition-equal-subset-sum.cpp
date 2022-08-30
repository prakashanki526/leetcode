class Solution {
public:
    // bool f(vector<int>&nums, int n, int k, vector<vector<int>>dp){
    //     if(k==0)
    //         return 1;
    //     if(n==0)
    //         return nums[n]==k;
    //     if(dp[n][k]!=-1)
    //         return dp[n][k];
    //     bool np=f(nums,n-1,k,dp);
    //     bool p=0;
    //     if(k>=nums[n])
    //     p=f(nums,n-1,k-nums[n],dp);
    //     return dp[n][k]=p|np;
    // }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        if(sum%2!=0)
            return 0;
        int k=sum/2;
        vector<vector<bool>>dp(nums.size(),vector<bool>(k+1,0));
        for(int i=0;i<nums.size();i++)
            dp[i][0]=1;
        if(nums[0]<=k)
            dp[0][nums[0]]=1;
        for(int i=1;i<nums.size();i++){
            for(int j=1;j<=k;j++){
                bool np=dp[i-1][j];
                bool p=0;
                if(j>=nums[i])
                    p=dp[i-1][j-nums[i]];
                dp[i][j]=p|np;
            }
        }
        return dp[nums.size()-1][k];
    }
};