class Solution {
public:
    string reverseWords(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++)
            st.push(s[i]);
        string res = "",temp= "";
        while(!st.empty()){
            if(st.top()==' '){
                while(st.top()==' ')
                    st.pop();
                reverse(temp.begin(),temp.end());
                res+=" "+ temp;
                temp = "";
            }
            else{
                temp += st.top();
                st.pop();
            }
        }
        reverse(temp.begin(),temp.end());
        res += " "+temp;
        int i=0;
        while(res[i]==' ')
            i++;
        string ans = res.substr(i,res.length());
        reverse(ans.begin(),ans.end());
        return ans;
    }
};