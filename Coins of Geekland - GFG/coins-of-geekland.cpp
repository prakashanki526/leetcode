//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    public:
    int Maximum_Sum(vector<vector<int>> &mat,int N,int K){
        // Your code goes here
        vector<vector<int>>m(N,vector<int>(N));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                m[i][j] = mat[i][j];
        }
        
        for(int j=0;j<N;j++)
            for(int i=1;i<N;i++)
                m[i][j] += m[i-1][j];
                
        for(int i=0;i<N;i++)
            for(int j=1;j<N;j++)
                m[i][j] += m[i][j-1];
                
        int res = INT_MIN;
        
        for(int i=K-1;i<N;i++){
            for(int j=K-1;j<N;j++){
                int left = (j-K < 0) ? 0 : m[i][j-K];
                int up = (i-K < 0) ? 0 : m[i-K][j];
                int tl = (i-K<0 || j-K<0)?0 : m[i-K][j-K];
                res = max(res, m[i][j]-left-up+tl);
            }
        }
        
        return res;
    }  
};

//{ Driver Code Starts.

int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
    	int N;
        cin>>N;
        vector<vector<int>> mat(N,vector<int>(N,0));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>mat[i][j];
            }
        }
        
        int k;cin>>k;
        Solution obj;
        cout << obj.Maximum_Sum(mat,N,k)<<"\n";
    }
        
    return 0;
}

// } Driver Code Ends