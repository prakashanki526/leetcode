//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solve(vector<int>&nums, int sum, int n){
	    if(n == 0){
	        if(sum%nums[0]==0)
	            return sum/nums[0];
	        return 1e8;
	    }
	    if(sum==0)
	        return 0;
	    int np = solve(nums,sum,n-1);
	    int p = INT_MAX;
	    if(nums[n]<=sum)
	        p = 1 + solve(nums,sum-nums[n],n);
	    return min(p,np);
	}
	int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	    sort(nums.begin(),nums.end());
	    int res = solve(nums,amount,nums.size()-1);
	    if(res >= 1e8)
	        return -1;
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends