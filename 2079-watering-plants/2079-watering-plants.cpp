class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int cnt=0, w=capacity;
        for(int i=0;i<plants.size();i++){
            if(plants[i]>w){
                cnt+= 2*i;
                i--;
                w = capacity;
                continue;
            }
            cnt++;
            w -= plants[i];
        }
        return cnt;
    }
};