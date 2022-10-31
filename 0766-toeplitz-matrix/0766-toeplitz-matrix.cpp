class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        // check first row and first col
        int n = matrix.size();
        for(int i=0; i<matrix[0].size(); i++){
            int r = 0, c = i, match = matrix[r][c];
            while(r<n and c<matrix[0].size()){
                if(matrix[r][c]!=match){
                    return 0;
                }
                r++, c++;
            }
        }
        for(int i=0; i<n; i++){
            int r = i, c = 0, match = matrix[r][c];
            while(r<n and c<matrix[0].size()){
                if(matrix[r][c]!=match){
                    return 0;
                }
                r++, c++;
            }
        }
        return 1;
    }
};