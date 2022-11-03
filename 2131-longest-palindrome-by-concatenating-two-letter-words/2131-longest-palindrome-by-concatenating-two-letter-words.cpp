class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int res = 0;
        unordered_map<string,int>m;
        for(int i=0;i<words.size();i++){
            string curr = words[i];
            string rev = curr;
            reverse(rev.begin(),rev.end());
            if(m.find(rev)!=m.end()){
                res += 4;
                m[rev]--;
                if(m[rev]==0)
                    m.erase(rev);
            }
            else{
                m[curr]++;
            }
        }
        for(auto it:m){
            if(it.first[0]==it.first[1]){
                res += 2;
                break;
            }
        }
        return res;
    }
};