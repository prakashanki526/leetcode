class Solution {
public:
    int countOdds(int low, int high) {
        if(low == high)
            return low%2 ? 1 : 0 ;
        if(low%2==0 && high%2==0)
            return (high-low)/2;
        return (high-low)/2 + 1;
    }
};