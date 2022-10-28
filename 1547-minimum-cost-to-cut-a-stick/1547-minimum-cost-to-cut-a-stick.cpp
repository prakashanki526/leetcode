class Solution {
public:
    int solve(vector<int>&v, int i, int j, vector<vector<int>>&dp){
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int mini = INT_MAX;
        for(int ind=i;ind<=j;ind++){
            int cost = v[j+1]-v[i-1] + solve(v,i,ind-1,dp) + solve(v,ind+1,j,dp);
            mini = min(mini,cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        int s = cuts.size();
        vector<vector<int>>dp(s,vector<int>(s,-1));
        return solve(cuts,1,cuts.size()-2,dp);
    }
};