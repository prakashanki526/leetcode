class Solution {
public:
    int minimumSum(int num) {
        string s = to_string(num);
        sort(s.begin(),s.end());
        string n1;
        n1 += s[0];
        n1+=s[2];
        string n2;
        n2 += s[1];
        n2+=s[3];
        int a = stoi(n1);
        int b = stoi(n2);
        return a+b;
    }
};