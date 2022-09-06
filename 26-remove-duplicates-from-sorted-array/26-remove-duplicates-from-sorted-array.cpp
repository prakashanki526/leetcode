class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         int n=nums.size(),l=0,r=0;
        while(r<n){
            if(nums[l]!=nums[r]){
                swap(nums[++l],nums[r++]);
            }
            else
                r++;
        }
        return ++l;
    }
};