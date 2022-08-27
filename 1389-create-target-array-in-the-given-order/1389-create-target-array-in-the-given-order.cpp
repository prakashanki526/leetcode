class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector target(nums.size(),-1);
for(int i = 0;i<nums.size();i++){
if(target[index[i]]==-1){
target[index[i]] = nums[i];
}
else{
int store = index.size()-1;
while(store>index[i]){
target[store]=target[store-1];
--store;
}
target[index[i]] = nums[i];
}
}
return target;
    }
};