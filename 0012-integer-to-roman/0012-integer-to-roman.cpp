class Solution {
    string arr[13] = {"I" , "IV","V"  ,"IX","X" , "XL","L", "XC","C" ,"CD", "D" , "CM","M"};
public:
    string intToRoman(int num) {
        int flag =0;
        string ans ="";
        while(num>0)
        {
            int x = num%10;
            if(x<=3)
            {
                while(x!=0){
                ans=arr[flag]+ans;
                    x--;}
                 
            }
            
            if(x==4)
            {
                ans=arr[flag+1]+ans;
            }
            
            if(x==5)
            {
                ans=arr[flag+2]+ans;
            }
            
            if(x<9 && x>5)
            {
                 while(x!=5){
                ans=arr[flag]+ans;
                    x--;}
                ans=arr[flag+2]+ans;
            }
            if(x==9)
            {
                ans=arr[flag+3]+ans;
            }
            
            num=num/10;
           flag=flag+4;
        }
        return ans;
    }
};