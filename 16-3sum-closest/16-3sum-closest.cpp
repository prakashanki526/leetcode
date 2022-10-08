class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // sort(nums.begin(),nums.end());
        // int res=INT_MAX,n=nums.size(),ans;
        // for(int i=0;i<n-2;i++){
        //     int l=i+1, r=n-1;
        //     while(l<r){
        //         int sum = nums[i]+nums[l]+nums[r];
        //         if(sum==target)
        //             return sum;
        //         if(abs(sum-target)<res){
        //             ans=sum;
        //             res=abs(sum-target);
        //         }
        //         if(sum<target)  l++;
        //         else    r--;
        //     }
        // }
        //       return ans;
        
        sort(nums.begin(),nums.end());
        int diff = 1e9, n = nums.size(), ans;
        for(int i=0;i<n-2;i++){
            int l=i+1, r=n-1;
            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
                if(sum==target)
                    return sum;
                if(diff>abs(sum-target)){
                    ans=sum;
                    diff=abs(sum-target);
                }
                if(sum>target)
                    r--;
                else
                    l++;
            }
        }
        return ans;
        
    }
};