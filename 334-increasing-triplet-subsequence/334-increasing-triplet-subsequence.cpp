class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)
            return 0;
        int mini = INT_MAX, mini2 = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mini2)
                return 1;
            if(mini2>nums[i] && nums[i]>mini)
                mini2 = nums[i];
            if(mini>nums[i])
                mini = nums[i];
        }
        return 0;
    }
};