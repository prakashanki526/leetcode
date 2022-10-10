class Solution {
public:
    string breakPalindrome(string palindrome) {
        // string s="";
        // if(palindrome.length()==1)
        //     return s;
        // for(int i=0;i<=palindrome.length()/2;i++){
        //     if(palindrome[i]!='a'){
        //         palindrome[i]='a';
        //         s = palindrome;
        //         break;
        //     }
        // }
        // if(s.length()>1)
        // return s;
        // s=palindrome;
        // s[s.length()-1]='b';
        // return s;
        if(palindrome.length() == 1) return "";
            
    for(int i = 0; i < palindrome.length() / 2; i++){
        if(palindrome[i] > 'a'){
            
            palindrome[i] = 'a';
            return palindrome;

        }
    }
    
    palindrome[palindrome.length() - 1] = 'b';
    
    return palindrome;
    }
};