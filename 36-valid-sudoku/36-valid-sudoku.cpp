class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
//         int n = 9;
//         int usedrow[9][9]={0}, usedcol[9][9]={0}, usedblock[9][9]={0}; 
//         for(int i=0; i<board.size(); i++){
//             for(int j=0; j<board[i].size(); j++){
//                 if(board[i][j] != '.'){
//                     int k = i/3*3 + j/3, num = board[i][j]-'0'-1;
//                     if(usedrow[i][num] || usedcol[j][num]|| usedblock[k][num]){
//                         return 0;
//                     }
//                         usedrow[i][num] == 1;
//                         usedcol[j][num]==1;
//                         usedblock[k][num]==1;
                    
//                 }
//             }
//         }
//         return 1;
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
        
        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
        
        return true;
    }
};