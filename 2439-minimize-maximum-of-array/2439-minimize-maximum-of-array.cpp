class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long int sum=nums[0];
        int res=0;
        vector<long long int>v;
        v.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            sum += nums[i];
            v.push_back(sum);
        }
        for(int i=0;i<v.size();i++){
            int curr = ceil(v[i]*1.0/(i+1));
            res = max(res,curr);
        }
            
        return res;
    }
};