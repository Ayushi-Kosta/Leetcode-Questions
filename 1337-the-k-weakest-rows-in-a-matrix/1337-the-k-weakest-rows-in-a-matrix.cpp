class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<vector<int>> v(n);
        for(int i=0; i<n; i++){
            int c =0;
            bool t= 1;
            int j=0;
            while(j<mat[i].size() and mat[i][j]==1){
                j++;
                c++;
            }
                v[i].push_back(c);
                    
                v[i].push_back(i);
        }
        sort(v.begin(), v.end());
        // for(int i=0; i<(n); i++){
        //     cout<<(v[i][1]);
        // }
        // cout<<"\n";
        vector<int> ans;
        for(int i=0; i<min(k, n); i++){
            ans.push_back(v[i][1]);
        }
        return ans;
    }
};