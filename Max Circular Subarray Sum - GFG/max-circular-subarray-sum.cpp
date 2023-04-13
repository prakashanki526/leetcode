//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
        
        // your code here
        int sum = 0, mini=0,cm=0, maxi=0,cmax=0, ge=INT_MIN;
        for(int i=0;i<num;i++){
            sum += arr[i];
            cm = min(cm+arr[i],arr[i]);
            mini = min(mini,cm);
            
            cmax = max(cmax+arr[i],arr[i]);
            maxi = max(maxi,cmax);
            ge = max(ge,arr[i]);
        }
        
        // cout<<sum<<" "<<mini<<" ";
        
        int res = max(sum-mini,maxi);
        
        return !res ? ge : res;
        
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends