class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0, cntl=0,cntr=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='L')
                cntl++;
            else
                cntr++;
            if(cntl == cntr)
                res++;
        }
        return res;
    }
};