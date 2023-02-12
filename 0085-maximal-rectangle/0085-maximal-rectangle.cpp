class Solution {
public:
    int MAH(vector<int>&v){
        int n = v.size();
        vector<int>left,right;
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first>=v[i])
                st.pop();
            if(st.empty())
                left.push_back(i+1);
            else
                left.push_back(i-st.top().second);
            st.push({v[i],i});
        }
        
        stack<pair<int,int>>s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top().first>=v[i])
                s.pop();
            if(s.empty())
                right.push_back(n-i);
            else
                right.push_back(s.top().second-i);
            s.push({v[i],i});
        }
        reverse(right.begin(),right.end());
        int res = INT_MIN;
        for(int i=0;i<n;i++)
            res = max(res,v[i]*(left[i]+right[i]-1));
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>>v(n,vector<int>(m));
        
        int res=-1;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(i==0){
                    v[i][j] = matrix[i][j] == '0' ? 0 : 1 ;
                } else
                    v[i][j] = matrix[i][j] == '0' ? 0 : v[i-1][j]+1 ;
            }
            res = max(res,MAH(v[i]));
        }
        
        return res;
    }
};