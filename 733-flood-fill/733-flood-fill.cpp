class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(), m=image[0].size();
        int inicolor = image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            image[row][col]=color;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&image[nrow][ncol]!=color&&image[nrow][ncol]==inicolor)
                    q.push({nrow,ncol});
            }
        }
        return image;
        
    }
};