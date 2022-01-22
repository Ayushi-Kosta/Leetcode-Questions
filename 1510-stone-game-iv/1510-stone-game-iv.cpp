class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1);
        for(int i=1; i<n+1; i++){
            for(int j=1; j*j<i+1; j++){
                if(!dp[i - j*j]){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};