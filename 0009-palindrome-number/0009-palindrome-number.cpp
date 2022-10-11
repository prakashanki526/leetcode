class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int l = 0, r = s.length()-1;
        while(l<r){
            if(s[l]!=s[r])
                return 0;
            l++;
            r--;
        }
        return 1;
    }
};