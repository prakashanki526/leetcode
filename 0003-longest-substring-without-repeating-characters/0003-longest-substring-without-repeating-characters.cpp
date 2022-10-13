class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)
            return 0;
        int res = 0, i=0, j=0;
        int arr[200] = {0};
        while(j<s.length()){
            if(arr[s[j]-0]==0){
                arr[s[j]-0]=1;
                res = max(res,j-i+1);
                j++;
            }
            else{
                arr[s[i]-0] = 0;
                i++;
            }
        }
        return res;
    }
};