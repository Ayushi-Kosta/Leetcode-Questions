class Solution {
public:
    int bitwiseComplement(int n) {
        int i=1, ans=0;
        if(n==0){
            return 1;
        }
        while(n){
            if(n%2==0){
                ans+=i;
                
            }
            n/=2;
            i*=2;
        }
        return ans;
    }
};