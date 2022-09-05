class Solution {
public:
    bool isAnagram(string s, string t) {
         if(s.length()!=t.length())
            return 0;
        vector<int>v(26);
        for(int i=0;i<s.length();i++){
            v[s[i]-97]++;
            v[t[i]-97]--;
        }
        for(int i=0;i<26;i++)
            if(v[i]!=0)
                return 0;
        return 1;
    }
};