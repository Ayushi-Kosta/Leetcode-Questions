class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n_r = mat.size(), n_c = mat[0].size();
        if(r==n_r and c==n_c){
            return mat;
        }
        else if(n_r*n_c != r*c){
            return mat;
        }
        else{
            //cout<<"n_r "<<n_r<<" n_c "<<n_c<<"\n";
            vector<int> v;
            for(int i=0; i<n_r; i++){
                for(int j=0; j<n_c; j++){
                    v.push_back(mat[i][j]);
                }    
            }
            vector<vector<int>> ans;
            // for(auto &x : v){
            //     cout<<x<<" ";
            // }
            //cout<<"\n";
            int k=0;
            for(int i=0; i<r; i++){
                vector<int> t;
                for(int j=0; j<c; j++){
                    t.push_back(v[k]);
                    k++;
                }    
                ans.push_back(t);
            }
            return ans;
        }
    }
};