class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>left,right;
        stack<pair<int,int>>st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && st.top().first>=heights[i])
                st.pop();
            if(st.empty())
                left.push_back(i+1);
            else
                left.push_back(i-st.top().second);
            st.push({heights[i],i});
        }
        
        while(!st.empty())
            st.pop();
        
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && st.top().first>=heights[i])
                st.pop();
            if(st.empty())
                right.push_back(heights.size()-i);
            else
                right.push_back(st.top().second-i);
            st.push({heights[i],i});
        }
        
        reverse(right.begin(),right.end());
        
        int res = INT_MIN;
        
        for(int i=0;i<heights.size();i++)
            res = max(res, heights[i]*(left[i]+right[i]-1));
        return res;
    }
};