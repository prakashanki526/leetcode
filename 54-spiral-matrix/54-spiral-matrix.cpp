class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        int top=0,left=0,right=m[0].size()-1,bottom=m.size()-1;
        vector<int>v;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++)
                v.push_back(m[top][i]);
            top++;
            
            for(int i=top;i<=bottom;i++)
                v.push_back(m[i][right]);
            right--;
            
            if(top<=bottom){
                for(int i=right;i>=left;i--)
                    v.push_back(m[bottom][i]);
                bottom--;
            }
            
            if(left<=right){
                for(int i=bottom;i>=top;i--)
                    v.push_back(m[i][left]);
                left++;
            }
        }
        return v;
    }
};