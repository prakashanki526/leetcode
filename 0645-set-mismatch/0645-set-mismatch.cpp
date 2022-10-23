class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>v(2);
        vector<int>m(nums.size()+1);
        for(auto it:nums)
            m[it]++;
        for(int i=1;i<=nums.size();i++){
            if(m[i]==0)
                v[1] = i;
            if(m[i]==2)
                v[0] = i;
        }
        return v;
    }
};