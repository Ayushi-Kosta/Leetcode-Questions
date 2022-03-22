class Solution {
public:
    string getSmallestString(int n, int k) {
        char a[n];
        for(int i=0; i<n; i++){
            a[i]='a';
        }
        k-=n;
        int i=n-1;
        while(n>=0 and k>0){
            a[i]+=min(k, 25);
            k-=25;
            i--;
        }
        string ans;
        for(int i=0; i<n; i++){
            ans+=a[i];
        }
        return ans;
    }
};