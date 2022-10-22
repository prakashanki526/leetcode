class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m;
        unordered_set<char>set;
        for(int i=0;i<t.length();i++){
            m[t[i]]++;
            set.insert(t[i]);
        }
        int res = INT_MAX,j=0, cnt=m.size();
        string ans = "";
        for(int i=0;i<s.length();i++){
            if(set.find(s[i])!=set.end()){
                m[s[i]]--;
                if(m[s[i]]==0){
                    m.erase(s[i]);
                    cnt--;
                }
            }
            while(cnt==0){
                if(res>i-j+1){
                    res = i-j+1;
                    ans = s.substr(j,i-j+1);
                }
                if(set.find(s[j])!=set.end()){
                    m[s[j]]++;
                    if(m[s[j]]==1)
                        cnt++;
                }
                j++;
            }
        }
        return ans;
    }
};