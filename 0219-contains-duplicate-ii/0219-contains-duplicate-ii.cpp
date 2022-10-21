class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>s;
        queue<int>q;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i])!=s.end())
                return 1;
            s.insert(nums[i]);
            q.push(nums[i]);
            if(q.size()>k){
                s.erase(q.front());
                q.pop();
            }
        }
        return 0;
    }
};