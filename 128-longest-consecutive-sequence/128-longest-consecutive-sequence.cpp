class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++)
            s.insert(nums[i]);
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1)==s.end()){
                int k=1,cnt=1;
                while(s.find(nums[i]+k)!=s.end()){
                    k++;
                    cnt++;
                }
                res=max(res,cnt);
            }
        }
        return res;
    }
};