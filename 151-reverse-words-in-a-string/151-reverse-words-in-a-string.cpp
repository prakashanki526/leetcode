class Solution {
public:
    string reverseWords(string s) {
        int f=0;
        string res,temp;
        stack<char>st;
        for(int i=0;i<s.length();i++)
            st.push(s[i]);
        
        while(!st.empty()){
            char c = st.top();
            st.pop();
            if(f==1 && c==' '){
                f=0;
                reverse(temp.begin(),temp.end());
                res+=temp+' ';
                temp="";
                while(!st.empty() && st.top()==' ')
                    st.pop();
            }
            else{
                temp+=c;
                f=1;
            }
        }
        reverse(temp.begin(),temp.end());
        res+=temp;
        while(res[res.length()-1]==' ')
            res.pop_back();
        int i=0;
        while(res[i]==' ')
            i++;
        return res.substr(i,res.length()-i);
        return res;
    }
};