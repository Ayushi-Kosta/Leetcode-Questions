class Solution {
public:
    int fib(int n) {
        int c=0, b=1, i=2;
        if(n==0) return c;
        if(n==1) return b;
        int a[n+1];
        a[0]=0, a[1]=1;
        while(i<=n){
            a[i]=a[i-1]+a[i-2];
            i++;
        }
        return a[n];
    }
};