class Solution {
public:
    int countPrimes(int n) {
        vector<bool>v(n,1);
        
        int cnt = 0;
        
        for(int i=2;i<n;i++){
            if(v[i]){
                cnt++;
                for(int j=i;j<n;j=j+i)
                    v[j] = 0;
            }
        }
        
        return cnt;
    }
};