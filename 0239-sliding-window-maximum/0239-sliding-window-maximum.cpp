class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>res;
        list<int>ls;
        int i=0, j=0;
        for(int j=0;j<n;j++){
            while(ls.size()>0 && ls.back()<nums[j])
                ls.pop_back();
            ls.push_back(nums[j]);
            if(j-i+1<k){
                continue;
            }
            if(j-i+1==k){
                res.push_back(ls.front());
                if(nums[i]==ls.front())
                    ls.pop_front();
                i++;
            }
        }
        return res;
    }
};