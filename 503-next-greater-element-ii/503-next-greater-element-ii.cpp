class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>v;
        stack<int>st;
        for(int i=nums.size()-1;i>=0;i--)
            st.push(nums[i]);
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i])
                st.pop();
            if(st.empty()){
                v.push_back(-1);
                st.push(nums[i]);
            }
            else{
                v.push_back(st.top());
                st.push(nums[i]);
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};