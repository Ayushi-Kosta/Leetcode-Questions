// class Solution {
// public:
//     bool isSafe(int x, int i, int j, int n, vector<vector<char>> &board){
//         for(int a=0; a<n; a++){
//             if(x==(board[a][j]-'0')){
//                 return 0;
//             }
//         }
//         for(int b=0; b<n; b++){
//             if(x==(board[i][b]-'0')){
//                 return 0;
//             }
//         }
//         int s = sqrt(n);
//         int r=i-(i%s), c=j-(j%s);
//         for(int a=0; a<s; a++){
//             for(int b=0; b<s; b++){
//                 if((board[a+r][b+c]-'0')==x){
//                     return 0;
//                 }
//             }
//         }
//         return 1;
//     }
//     bool solverec(vector<vector<char>> &board, int n){
//         int i=0, j=0;
//         bool t=0;
//         for(i=0; i<n; i++){
//             for(j=0; j<n; j++){
//                 if(board[i][j]=='.'){
//                     t=1;
//                     break;
//                 }
//             }
//             if(t){
//                 break;
//             }
//         }
//             if(i==n and j==n){
//                 return 1;
//             }
//             for(int x=1; x<=n; x++){
//                 if(isSafe(x, i, j, n, board)){
//                     board[i][j]=x+'0';
//                     if(solverec(board, n)){
//                         return 1;
//                     }
//                     board[i][j]='.';
//                 }
//             }
        
//         return 0;
//     }
//     void solveSudoku(vector<vector<char>>& board) {
//         int n=board.size();
//         solverec(board, n);
//     }

// };


class Solution {
private:
    bool isSafe(int i, int j, char ch, vector<vector<char>>&board) {
        for(int k = 0; k<9; k++) {
            if(board[k][j] == ch || board[i][k] == ch) 
                return false;
        }
        int rs = i - i%3, cs = j - j%3;
        for(int r = 0; r<3; r++) {
            for(int c = 0; c<3; c++) {
                if(board[r+rs][c+cs] == (ch)) return false;
            }
        }
        return true;
    }
private:
    vector<int> findEmpty(vector<vector<char>>&baord) {
        for(int i = 0; i<9; i++) {
            for(int j = 0; j<9; j++) {
                if(baord[i][j] == '.') return {i, j};
            }
        }
        return {};
    }
public:
    bool solve(vector<vector<char>> &board) {
        vector<int> ind = findEmpty(board);
        int i, j;
        if(ind.empty()) return true;
        else
            i = ind[0], j = ind[1];
        for(char c = '1'; c<='9'; c++) {
            if(isSafe(i, j, c, board)) {
                board[i][j] = c;
                if(solve(board)) return true;
                board[i][j] = '.';
            }
            
        }
        return false;
    }

public:    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

















