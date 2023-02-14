class Solution {
public:
    string addBinary(string a, string b) {
        string res="";
        int carry = 0;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int n = min(a.length(),b.length());
        for(int i=0;i<n;i++){
            res += to_string((a[i]-'0') ^ (b[i]-'0') ^ carry);
            carry = ((a[i]-'0')&&(b[i]-'0') || (a[i]-'0')&&carry || (b[i]-'0')&&carry);
        }
        if(a.length() > n){
            for(int i=n; i<a.length(); i++){
                res += to_string((a[i]-'0')^carry);
                carry = (a[i]-'0')&&carry;
            }
        }
        if(b.length()>n){
            for(int i=n; i<b.length(); i++){
                res += to_string((b[i]-'0')^carry);
                carry = (b[i]-'0')&&carry;
            }
        }
        if(carry)
            res += to_string(carry);
        reverse(res.begin(),res.end());
        return res;
    }
};