class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0)
            return true;
        int i=0,cnt=0;
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);
        while(i<flowerbed.size()-2 && cnt<n){
            if(flowerbed[i]==0 && flowerbed[i+1]==0 && flowerbed[i+2]==0){
                flowerbed[i+1] = 1;
                ++cnt;
            }
            ++i;
        }
        if(n==cnt)
            return true;
        return false;
    }
};