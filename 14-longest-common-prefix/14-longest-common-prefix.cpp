class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res=strs[0];
        int f=0,k=0;
        for(int i=0;i<res.length();i++){
            for(int j=1;j<strs.size();j++){
                if(strs[j].length()<=i || strs[j][i]!=res[i]){
                    f=1;
                    break;
                }
            }
            if(f==1)
                break;
            k++;
        }
        return res.substr(0,k);
    }
};