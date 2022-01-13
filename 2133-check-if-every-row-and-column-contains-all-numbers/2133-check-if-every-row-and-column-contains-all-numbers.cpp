class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        bool f1=1, f2=1;
        for(int i=0; i<n; i++){
            unordered_map<int, int> m;
            for(int j=0; j<n; j++){
                m[matrix[i][j]]++;
            }
            for(int i=1; i<=n; i++){
                if(m[i]<=0 or m[i]>1){
                    return 0;
                }
            }
        }
        for(int i=0; i<n; i++){
            unordered_map<int, int> m;
            for(int j=0; j<n; j++){
                m[matrix[j][i]]++;
            }
            for(int i=1; i<=n; i++){
                if(m[i]<=0 or m[i]>1){
                    return 0;
                }
            }
        }
        
            return 1;
        
    }
};