class Solution {
public:
    int m = 1e9+7;
    int countOrders(int n) {
        long long s = 1;
        // n!*(1*3*5*.......*(2*n -1))
        for(int i=1; i<=n; i++){
            s=s*i%m;
        }
        for(int i=1; i<=(2*n-1); i+=2){
            s=((s%m)*i)%m;
        }
        return s;
    }
};