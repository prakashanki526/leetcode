class Solution {
public:
    void make_island0(vector<vector<char>>&grid,int i, int j, int m, int n){
        if(i<0 || j<0 || i==n || j==m || grid[i][j]=='0')
            return;
        grid[i][j]='0';
        make_island0(grid,i+1,j,m,n);
        make_island0(grid,i,j+1,m,n);
        make_island0(grid,i-1,j,m,n);
        make_island0(grid,i,j-1,m,n);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    res++;
                    make_island0(grid,i,j,m,n);
                }
            }
        }
        return res;
    }
};