class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
            {
                k=i;
                break;
            }
        }
        for(int i=k+1;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[k++],nums[i]);
            }
        }
    }
};