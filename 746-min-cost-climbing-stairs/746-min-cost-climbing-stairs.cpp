class Solution {
public:
    int f(vector<int>&cost, int n){
        if(n==0)
            return cost[n];
        if(n<0)
            return 0;
        int one= cost[n]+f(cost,n-1);
        int two= cost[n]+f(cost,n-2);
        return min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // return f(cost,cost.size()-1);
        int dp[cost.size()];
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<cost.size();i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[cost.size()-2],dp[cost.size()-1]);
    }
};