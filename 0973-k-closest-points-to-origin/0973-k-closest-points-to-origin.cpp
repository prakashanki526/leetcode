class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>res;
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<points.size();i++){
            int p = points[i][0];
            int q = points[i][1];
            pq.push({p*p+q*q,{p,q}});
            if(pq.size()>k)
                pq.pop();
        }
        while(!pq.empty()){
            res.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return res;
    }
};