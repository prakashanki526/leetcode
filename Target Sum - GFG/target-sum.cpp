//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int solve(vector<int>&v, int n, int target){
        if(n==0){
            if(v[n]==0 && target==0) return 2;
            if(target==0 || v[0] == target) return 1;
            return 0;
        }

        int np = solve(v,n-1,target);
        int p = 0;
        if(v[n]<=target)
            p = solve(v,n-1,target-v[n]);
        return p+np;
    }
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        int sum = 0;
        for(int i=0;i<A.size();i++)
            sum += A[i];
        if((sum-target)%2 != 0)
            return 0;
        return solve(A,A.size()-1,(sum-target)/2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends