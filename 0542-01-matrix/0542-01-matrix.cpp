class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>>q;
        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
	    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            mat[r][c] = d;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},d+1});
                }
            }
        }
        return mat;
    }
};