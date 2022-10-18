class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string s=countAndSay(n-1);
        string t;
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            cnt++;
            if(i==s.length()-1 || s[i]!=s[i+1])
            {
                t+=to_string(cnt);
                t+=s[i];
                cnt=0;
            }
        }
        return t;
    }
};