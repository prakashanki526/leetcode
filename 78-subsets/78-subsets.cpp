class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>v;
        int n=nums.size();
        for(int i=0;i<pow(2,n);i++){
            vector<int>w;
            for(int j=0;j<n;j++){
                if((1<<j)& i)
                    w.push_back(nums[j]);
            }
            v.push_back(w);
        }
        return v;
    }
};