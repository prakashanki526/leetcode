class Solution {
public:
    string pushDominoes(string dominoes) {
        int right = -1;
        for(int i=0;i<dominoes.length();i++){
            if(dominoes[i]=='L'){
                if(right==-1){
                    int k = i;
                    while(k-1>=0 && dominoes[k-1]=='.'){
                        dominoes[k-1]='L';
                        k--;
                    }
                }
                else{
                    int k = i-1;
                    right++;
                    while(right<k){
                        dominoes[right++]='R';
                        dominoes[k--]='L';
                    }
                    right=-1;
                }
            }
            if(dominoes[i]=='R'){
                if(right!=-1){
                    int k = i;
                    while(k-1>=0 && dominoes[k-1]=='.'){
                        dominoes[k-1]='R';
                        k--;
                    }
                }
                right=i;
            }
        }
        if(right!=-1){
            for(int i=right+1;i<dominoes.length();i++)
                dominoes[i]='R';
        }
        return dominoes;
    }
};