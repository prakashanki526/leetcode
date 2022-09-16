class Solution {
public:
    int f(vector<int>&nums, vector<int>&mul, int s, int e, int m, vector<vector<int>>&dp){
        if(m==mul.size()-1)
            return max(nums[s]*mul[m],nums[e]*mul[m]);
        if(dp[s][m]!=INT_MIN)
            return dp[s][m];
        int pf = nums[s]*mul[m] + f(nums,mul,s+1,e,m+1,dp);
        int pl = nums[e]*mul[m] + f(nums,mul,s,e-1,m+1,dp);
        return dp[s][m]=max(pf,pl);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector<vector<int>>dp(multipliers.size(),vector<int>(multipliers.size(),INT_MIN));
        return f(nums,multipliers,0,nums.size()-1,0,dp);
    }
};