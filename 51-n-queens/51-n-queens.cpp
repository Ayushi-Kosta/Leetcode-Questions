class Solution {
public:
    bool isSafe(int n, int row, int col, vector<string> &board){
        
        for(int i=0; i<col; i++){
            if(board[row][i]=='Q'){
                return 0;
            }
        }
        for(int i=row, j=col; i>=0 and j>=0; i--, j--){
            if(board[i][j]=='Q'){
                return 0;
            }
        }
        for(int i=row, j=col; i<n and j>=0; i++, j--){
            if(board[i][j]=='Q'){
                return 0;
            }
        }
        return 1;
    }
    bool solverec(int n, int col, vector<string> board, vector<vector<string>> &v){
        if(col==n){
            return 1;
        }
        for(int i=0; i<n; i++){
            if(isSafe(n, i, col, board)){
                board[i][col]='Q';
                if(solverec(n, col+1, board, v)){
                    v.push_back(board);
                    string s;
                    for(int i=0; i<n; i++){
                        s+='.';
                    }
                    for(auto &x: board){
                        x=s;
                    }
                    
                    break;
                }
                board[i][col]='.';
            }
        }
        return 0;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> v;
        vector<string> a;
        string s;
        for(int i=0; i<n; i++){
            s+='.';
        }
        for(int i=0; i<n; i++){
            a.push_back(s);
        }
        bool t = solverec(n, 0, a, v);
            return v;
        
    }
};