class Solution {
public:
    int f(vector<int>&n1, vector<int>&n2, int n, int m){
        if(n==0 || m==0){
            return n1[n]==n2[m];
        }
        int p = 1+f(n1,n2,n-1,m-1);
        int np = max(f(n1,n2,n-1,m),f(n1,n2,n,m-1));
        return max(p,np);
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        // return f(nums1,nums2,n-1,m-1);
        int res=0;
        for(int i=1;i<=n;i++){
            int j=1;
            for(j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    res=max(res,dp[i][j]);
                }
                else
                    dp[i][j]=0;
            }
        }
        return res;
    }
};