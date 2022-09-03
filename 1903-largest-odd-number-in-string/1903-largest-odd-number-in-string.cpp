class Solution {
public:
    string largestOddNumber(string num) {
        int i;
        string s="";
        for(i=num.length()-1;i>=0;i--){
            if(num[i]%2!=0)
                break;
        }
        if(i==-1)
            return s;
        return num.substr(0,i+1);
    }
};