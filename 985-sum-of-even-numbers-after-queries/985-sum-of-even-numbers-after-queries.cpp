class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>res;
        int se=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]%2==0)
                se+=nums[i];
        for(int i=0;i<queries.size();i++){
            if(nums[queries[i][1]]%2==0)
                se-=nums[queries[i][1]];
            nums[queries[i][1]]+=queries[i][0];
            if(nums[queries[i][1]]%2==0)
                se+=nums[queries[i][1]];
            res.push_back(se);
        }
        return res;
    }
};