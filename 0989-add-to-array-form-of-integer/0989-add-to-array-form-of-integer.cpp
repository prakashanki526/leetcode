class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>v;
        reverse(num.begin(),num.end());
        int carry = 0;
        for(int i=0;i<num.size();i++){
            v.push_back((num[i]+(k%10)+carry)%10);
            carry = (num[i]+(k%10)+carry)/10;
            k /= 10;
        }
        while(k){
            v.push_back(((k%10)+carry)%10);
            carry = ((k%10)+carry)/10;
            k/=10;
        }
        if(carry){
            v.push_back(carry);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};