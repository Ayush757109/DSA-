class Solution {
public:
    int reverse(int x) {
       int sign =0;
       if(x<0) sign=1;
       long long num =x;
       num =abs(num);
       long long rev=0;
       while(num!=0){
        int digit= num%10;
        rev = rev*10 + digit;
        num /=10;
       }
       if(sign==1) {
        rev *=-1;
       }
       if(rev>INT_MAX)  return 0;
       if(rev<INT_MIN)  return 0;
     return rev;
    }
};