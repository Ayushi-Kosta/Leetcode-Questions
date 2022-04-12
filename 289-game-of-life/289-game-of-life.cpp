// class Solution {
// public:
//     void gameOfLife(vector<vector<int>>& board) {
//         int n=board.size(), m=board[0].size(), mat[n][m];
//         for(int i=1; i<n-1; i++){
//             for(int j=1; j<n-1; j++){
//                 int a1=0, a2=0, a3=0, a4=0, a5=0, a6=0, a7=0, a8=0;
//                 if(i>0 and j>0) a1=board[i-1][j-1];
//                 if(i>0) a2=board[i-1][j];
//                 if(i>0 and j<n-1) a3=board[i-1][j+1];
//                 if(i<n-1 and j>0) a4=board[i+1][j-1];
//                 if(i<n-1) a5=board[i+1][j];
//                 if(i<n-1 and j<n-1) a6=board[i+1][j+1];
//                 if(j>0) a7=board[i][j-1];
//                 if(j<n-1) a8=board[i][j+1];
//                 long long at = a1+a2+a3+a4+a5+a6+a7+a8;
//                 if(at<2 or at>3){
//                     mat[i][j]=0;
//                 }
//                 else if(at==3){
//                     mat[i][j]=1;
//                 }
//             }            
//         }
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 board[i][j]=mat[i][j];
//             }
//         }
        
//     }
// };
    class Solution {
    
    vector<vector<int>> dirs = {
        {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0, -1}, {-1,-1} 
    };

    int getNeighbors(vector<vector<int>>& board, int r, int c) {
        int howManyAlive = 0;
        for(auto& dir : dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if(nr < 0 || nr >= board.size()) continue;
            if(nc < 0 || nc >= board[r].size()) continue;
            
            howManyAlive += board[nr][nc];
        }
        return howManyAlive;
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        int ROWS = board.size();
        int COLS = board[0].size();
        
        vector<vector<int>> newBoard(ROWS, vector<int>(COLS));
        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                int howManyAlive = getNeighbors(board, r, c);
                if(board[r][c] == 0 && howManyAlive == 3) {
                    newBoard[r][c] = 1;
                } else if (board[r][c] == 1 && howManyAlive < 2) {
                    newBoard[r][c] = 0;
                } else if (board[r][c] == 1 && howManyAlive > 3) {
                    newBoard[r][c] = 0;
                } else if (board[r][c] == 1) {
                    newBoard[r][c] = 1;
                }
            }
        }
        board = newBoard;
        return;
    }
};