class Solution {
public:
    static bool comp(pair<int,int>&a,pair<int,int>&b){
        return a.second>b.second;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>v;
        for(int i=0;i<plantTime.size();i++)
            v.push_back({plantTime[i],growTime[i]});
        sort(v.begin(),v.end(),comp);
        int sum = 0, lead = 0;
        for(int i=0;i<v.size();i++){
            if(v[i].first>lead){
                sum += v[i].first;
                lead = v[i].second;
            }
            else{
                sum += v[i].first;
                lead -= v[i].first;
                lead = max(lead,v[i].second);
            }
        }
        return sum+lead;
    }
};