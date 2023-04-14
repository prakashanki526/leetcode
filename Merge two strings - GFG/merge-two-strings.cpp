//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

string merge (string s1, string s2);

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << merge (s1, s2) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends



string merge (string S1, string S2)
{
    // your code here
    string s;
    int n = S1.length(), m = S2.length(), i=0, j=0;
    
    while(i<n && j<m){
        s += S1[i++];
        s += S2[j++];
    }
    
    while(i<n)
        s += S1[i++];
        
    while(j<m)
        s += S2[j++];
        
    return s;
}