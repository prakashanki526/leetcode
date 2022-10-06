class Solution {
public:
    void dfs(vector<int>adjls[], vector<bool>&vis, int i){
        for(auto it:adjls[i]){
            if(!vis[it]){
                vis[it]=1;
                dfs(adjls,vis,it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adjls[n+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j)
                    adjls[i+1].push_back(j+1);
            }
        }
        vector<bool>vis(n+1,0);
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vis[i]=1;
                cnt++;
                dfs(adjls,vis,i);
            }
        }
        return cnt;
    }
};