class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n= accounts.size(), m=accounts[0].size();
        vector<int> v(n);
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=0; j<m; j++){
                sum+=accounts[i][j];
            }
            v[i]=sum;
        }
        int maxi=0, index=-1;
        for(int i=0; i<n; i++){
            if(maxi<v[i]){
                maxi=v[i];
                index=i;
            }
        }
        return maxi;
    }
};