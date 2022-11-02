class Solution {
public:
    bool check(string &s, string &t){
        int f=1,n=s.length(),m=t.length();
        if(n!=m)
            return 0;
        int i=0;
        while(i<n && f>=0){
            if(s[i]!=t[i])
                f--;
            i++;
        }
        return f == 0;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string>s(bank.begin(),bank.end());
        queue<pair<string,int>>q;
        q.push({start,0});
        int n=bank.size();
        unordered_map<string,int>vis;
        vis[start] = 1;
        while(!q.empty()){
            string curr = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if(curr==end)
                return cnt;
            for(int i=0;i<n;i++){
                string temp = bank[i];
                if(vis[temp]!=1 && check(curr,temp)){
                    q.push({temp,cnt+1});
                    vis[temp] = 1;
                }
            }
        }
        return -1;
    }
};