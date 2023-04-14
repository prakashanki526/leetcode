//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int CHARS = 26;

// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2);

// Driver program to run the case
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        cout << remAnagram(str1, str2);
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends


// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2)
{
// Your code goes here
    int arr[26] = {0};
    for(int i=0;i<str1.length();i++)
        arr[str1[i]-'a']++;
    
    for(int i=0;i<str2.length();i++)
        arr[str2[i]-'a']--;
        
    int res=0;
    for(int i=0;i<26;i++)
        res += abs(arr[i]);
        
    return res;
}