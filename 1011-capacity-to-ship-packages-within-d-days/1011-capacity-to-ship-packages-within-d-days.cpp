class Solution {
public:
    bool isPossible(vector<int>&weights, int days, int cap){
        int sum = 0;
        for(int i=0;i<weights.size();i++){
            sum += weights[i];
            if(sum>cap){
                sum = weights[i];
                days--;
                if(days==0)
                    return 0;
            }
        }
        return 1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=INT_MIN, sum=0;
        for(int i=0;i<weights.size();i++){
            sum += weights[i];
            maxi = max(maxi,weights[i]);
        }
        int start=maxi, end = sum, res=INT_MAX;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isPossible(weights,days,mid)){
                res = min(res,mid);
                end = mid-1;
            }
            else
                start = mid + 1;
        }
        return res;
    }
};