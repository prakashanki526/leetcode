//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        int arr[26] = {0};
        for(int i;i<str.length();i++)
            arr[str[i]-'a']++;
            
        int maxi=0;
        char res;
        
        for(int i=0;i<26;i++){
            if(maxi<arr[i]){
                maxi = arr[i];
                res = i + 'a';
            }
        }
        
        return res;
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends