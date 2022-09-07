class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s=0,e=nums.size()-1;
        for(int i=0;i<=e;i++){
            if(nums[i]==0)
                swap(nums[i],nums[s++]);
            else if(nums[i]==2)
                swap(nums[i--],nums[e--]);
        }
    }
};