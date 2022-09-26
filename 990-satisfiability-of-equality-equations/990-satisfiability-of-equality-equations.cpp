// class Solution {
// public:
//     vector<char>v;
//     char findroot(char c){
//         if(v[c]==c)
//             return c;
//         return findroot(v[c]);
//     }
//     bool equationsPossible(vector<string>& eq) {
//         v.resize(26);
//         for(int i=0;i<26;i++)
//             v[i]=i;
//         for(auto s:eq){
//             if(s[1]=='='){
//                 char x = findroot(s[0]-'a');
//                 char y = findroot(s[3]-'a');
//                 if(x!=y)
//                     v[y]=x;
//             }
//             if(s[1]=='!'){
//                 char x = findroot(s[0]-'a');
//                 char y = findroot(s[3]-'a');
//                 if(x==y)
//                     return 0;
//             }
//         }
//         return 1;
//     }
// };

class Solution {
    vector<char>parent;
    char rootfind(char x) {
        return parent[x] == x ? x : rootfind(parent[x]);
    }
public:
    bool equationsPossible(vector<string>& equations) {
       parent.resize(26, 0);
        for (int i = 0; i < 26; i++)
            parent[i] = i;
        for (auto strng: equations) {
            if (strng[1] == '=') {
                char x = rootfind(strng[0]-'a');
                char y = rootfind(strng[3]-'a');
                if (x != y)
                    parent[y] = x;
            }
        }
        for (auto strng: equations) {
            if (strng[1] == '!') {
                int x = rootfind(strng[0]-'a');
                int y = rootfind(strng[3]-'a');
                if (x == y)
                    return false;
            }
        }
        return true;
    }
};