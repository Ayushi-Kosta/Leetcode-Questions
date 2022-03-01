class Solution {
public:
    int subtractProductAndSum(int n) {
        int mul = 1, ad = 0;
        while(n){
            mul*=(n%10);
            ad+=(n%10);
            n/=10;
        }
        return (mul-ad);
    }
};