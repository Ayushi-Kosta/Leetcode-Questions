class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        long long dp[amount+1];
        dp[0]=0;
        long long n_c = coins.size();
        for(int i=1; i<amount+1; i++){
            dp[i]=INT_MAX;
            for(int j=0; j<n_c; j++){
                if(i>=coins[j]){
                    long long r = dp[i-coins[j]];
                    dp[i] = min(r+1, dp[i]);
                }
            }            
        }
        if(dp[amount]>=INT_MAX){
            return -1;
        }
        //cout<<(INT_MAX);
        return dp[amount];
    }
};