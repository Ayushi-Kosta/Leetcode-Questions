class Solution {
public:
    int s(vector<vector<int>> &dp, vector<int>& coins, int amount, int i){
        if(i<0 || amount<0){
            return 1e7;
        }
        if(amount==0){
            return 0;
        }
        if(dp[amount][i] != -1){
            return dp[amount][i];
        }
        return dp[amount][i] = min(1+s(dp, coins, amount-coins[i], i), s(dp, coins, amount, i-1));
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(amount+1, vector<int>(n, -1));
        // row->amount, column->denomination        
        int a = s(dp, coins, amount, n-1);
        if(a==1e7) return -1;
        return a;
    }
};
