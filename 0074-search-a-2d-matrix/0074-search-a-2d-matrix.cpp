class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix[0].size(), row=0, col=n-1;
        for(int i=0; i<matrix.size(); i++){
            if(matrix[i][n-1]>=target){
                row=i;
                break;
            }
        }
        // cout<<row<<" ";
        for(int i=0; i<matrix[0].size(); i++){
            if(matrix[row][i]==target){
                return 1;
            }
        }
        return 0;
    }
};