//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        string temp="";
        int start=0;
        for(int i=0;i<S.length();i++){
            if(S[i]=='.'){
                reverse(S.begin()+start, S.begin()+i);
                start = i+1;
            }
        }
        
        if(start != S.length()){
            reverse(S.begin()+start,S.end());
        }
        
        reverse(S.begin(),S.end());
        
        return S;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends