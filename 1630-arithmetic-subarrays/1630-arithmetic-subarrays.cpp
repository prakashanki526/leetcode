class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>res;
        
        for(int i=0;i<l.size();i++){
            int left = l[i];
            int right = r[i];
            
            vector<int>temp=nums;
            sort(temp.begin()+left, temp.begin()+right+1);
            
            int d = temp[left+1]-temp[left];
            
            int f=0;
            
            for(int j=left+2;j<=right;j++){
                if(temp[j]-temp[j-1] != d){
                    f=1;
                    break;
                }
            }
            
            f ? res.push_back(false) : res.push_back(true);
        }
        
        return res;
    }
};