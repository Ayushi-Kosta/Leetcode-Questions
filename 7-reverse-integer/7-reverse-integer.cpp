class Solution {
public:
    int reverse(int x) {
        char sign='+';
        if(x<0){
            sign='-';
        }
        long long s=0;
        while(x){
            s=s*10 + (x%10);
            x/=10;
        }
        if(s<INT_MIN or s>INT_MAX){
            return 0;
        }
        // if(sign=='-') return -s;
        // else{
            return s;
        // }
    }
};