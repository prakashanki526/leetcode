class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cnt = 0,k=0;
        for(int i=0;i<s.length();i++){
            for(int j=k;j<t.length();j++){
                if(s[i]==t[j]){
                    cnt++;
                    k=j+1;
                    break;
                }
            }
        }
        return cnt == s.length();
    }
};