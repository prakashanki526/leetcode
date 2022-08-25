class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>v(26);
        for(int i=0;i<magazine.length();i++)
            v[magazine[i]-'a']++;
        for(int i=0;i<ransomNote.length();i++){
            if(v[ransomNote[i]-'a']<1)
                return false;
            else
                v[ransomNote[i]-'a']--;
        }
        return true;
    }
};