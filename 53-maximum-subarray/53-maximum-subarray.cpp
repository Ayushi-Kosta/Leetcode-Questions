class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int n=a.size(), ans=a[0], res=a[0];
        for(int i=1; i<n; i++){
            ans=max(ans+a[i], a[i]);
            res=max(ans, res);
        }
        return res;
    }
};