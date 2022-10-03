class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        for(int i=1;i<colors.length();i++){
            int sum=0, maxi = 0;
            if(colors[i]==colors[i-1]){
                sum = neededTime[i-1];
                maxi = neededTime[i-1];
            }
            while(colors[i]==colors[i-1]){
                sum+=neededTime[i];
                maxi = max(maxi,neededTime[i]);
                i++;
            }
            res += sum-maxi;
        }
        return res;
    }
};