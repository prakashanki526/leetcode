//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int>v;
        int s1=0,s2=0;
        while(s1<n && s2<m){
            if(arr1[s1]<arr2[s2]){
                v.push_back(arr1[s1]);
                int x = arr1[s1];
                while(s1<n && arr1[s1]==x)
                    s1++;
            }
            else if(arr1[s1]>arr2[s2]){
                v.push_back(arr2[s2]);
                int x = arr2[s2];
                while(s2<m && arr2[s2]==x)
                    s2++;
            }
            else{
                v.push_back(arr1[s1]);
                int x1 = arr1[s1];
                while(s1<n && arr1[s1]==x1)
                    s1++;
                int x2 = arr2[s2];
                while(s2<m && arr2[s2]==x2)
                    s2++;
            }
        }
        while(s1<n){
            v.push_back(arr1[s1]);
            int x = arr1[s1];
            while(s1<n && arr1[s1]==x)
                s1++;
        }
        while(s2<m){
            v.push_back(arr2[s2]);
            int x = arr2[s2];
            while(s2<m && arr2[s2]==x)
                s2++;
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends