class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> edges;
    int left, right, height;
    for(int i=0; i<buildings.size(); i++){
        left=buildings[i][0];
        right=buildings[i][1];
        height=buildings[i][2];
        /* for the same left point we use the bigger height*/
        edges.push_back(make_pair(left, -height));
        edges.push_back(make_pair(right, height));
    }
    sort(edges.begin(), edges.end());
    vector<vector<int>> result;
    /* use the multiset to store the max height util current pos */
    multiset<int> m;
    /* left most height */
    m.insert(0);
    int pre=0, cur=0;
    for(int i=0; i<edges.size(); i++){
        pair<int, int> e=edges[i];
        vector<int>v1;
        if(e.second < 0)  m.insert(-e.second);
        else m.erase(m.find(e.second));
        cur=*(m.rbegin());
        if(cur!=pre){
            v1.push_back(e.first);
            v1.push_back(cur);
            result.push_back(v1);
            pre=cur;
        }
    }
    return result;
    }
};