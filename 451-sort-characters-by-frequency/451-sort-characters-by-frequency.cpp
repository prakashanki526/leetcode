class Solution {
public:
    bool static comp(pair<char,int>&a,pair<char,int>&b){
        if(a.second==b.second)
            return a<b;
        return a.second>b.second;
    }
    
    string frequencySort(string s) {
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++)
            m[s[i]]++;
        vector<pair<char,int>>v;
        for(auto it:m)
            v.push_back(it);
        string res="";
        sort(v.begin(),v.end(),comp);
        for(int i=0;i<v.size();i++){
            while(v[i].second--)
                res+=v[i].first;
        }
        return res;
    }
};