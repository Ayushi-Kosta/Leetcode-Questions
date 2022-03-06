class Solution {
public:
    int s(int n){
        int a = n, s=0;
        while(a){
            s+=((a%10)*(a%10));
            a=a/10;
        }
        return s;
    }
    bool isHappy(int n) {
        int a = n;
        while(n>6){
            int z = s(n);
            n=z;
            //cout<<z<<" ";
        }
        if(n==1) return 1;
        return 0;
    }
};