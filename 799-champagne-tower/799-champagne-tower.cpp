class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[100][100] = {0};
        dp[0][0] = poured;
        for(int i=0; i<100-1; i++){
            for(int j=0; j<=i; j++){
                if(dp[i][j] > 1){
                    dp[i+1][j] += ((double)(dp[i][j]-1))/2;
                    dp[i+1][j+1] += ((double)(dp[i][j]-1))/2;
                    dp[i][j] = 1;
                }
            }
        }
        return dp[query_row][query_glass];
    }
};