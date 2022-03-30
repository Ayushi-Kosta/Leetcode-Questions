class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m=matrix[0].size();
        for(int i=0; i<n; i++){
            if(matrix[i][m-1]>target){
                for(int j=0; j<m; j++){
                    if(matrix[i][j]==target){
                        return 1;
                    }
                }
            }
            else if(matrix[i][m-1]<target){
                
            }
            else {
                return 1;
            }
        }
        return 0;
    }
};