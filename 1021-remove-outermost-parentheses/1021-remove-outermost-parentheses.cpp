class Solution {
public:
    string removeOuterParentheses(string s) {
        int start=0, end=0, flag=0;
        string ans;
        stack<char>st1,st2;
        for(int i=0;i<s.length();i++){
            if(flag==0){
                start=i;
                flag=1;
            }
            if(s[i]=='(')
                st1.push(s[i]);
            else
                st2.push(s[i]);
            if(st1.size()==st2.size()){
                end=i;
                while(!st1.empty())st1.pop();
                while(!st2.empty())st2.pop();
                ans+=s.substr(start+1,end-start-1);
                flag=0;
            }
        }
        return ans;
    }
};