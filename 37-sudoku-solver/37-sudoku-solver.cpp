class Solution {
public:
    bool isSafe(int x, int i, int j, int n, vector<vector<char>> &board){
        for(int a=0; a<n; a++){
            if(x==(board[a][j]-'0')){
                return 0;
            }
        }
        for(int b=0; b<n; b++){
            if(x==(board[i][b]-'0')){
                return 0;
            }
        }
        int s = sqrt(n);
        int r=i-(i%s), c=j-(j%s);
        for(int a=0; a<s; a++){
            for(int b=0; b<s; b++){
                if((board[a+r][b+c]-'0')==x){
                    return 0;
                }
            }
        }
        return 1;
    }
    bool solverec(vector<vector<char>> &board, int n){
        int i=0, j=0;
        bool t=0;
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                if(board[i][j]=='.'){
                    t=1;
                    break;
                }
            }
            if(t){
                break;
            }
        }
            if(i==n and j==n){
                return 1;
            }
            for(int x=1; x<=n; x++){
                if(isSafe(x, i, j, n, board)){
                    board[i][j]=x+'0';
                    if(solverec(board, n)){
                        return 1;
                    }
                    board[i][j]='.';
                }
            }
        
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();
        solverec(board, n);
    }

};