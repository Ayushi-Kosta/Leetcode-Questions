class Solution {
public:
int m, n;
long long mod = 1e9+7;

int solve(int i, int j, int k, vector<vector<int>> &apples, vector<vector<vector<int>>> &dp){
    if (apples[i][j] < k){
        return 0;
    }
    if (k == 1){
        if (apples[i][j] >= 1){
            return 1;
        }
        return 0;
    }    
    if (dp[i][j][k] != -1) return dp[i][j][k];
    
    int ans = 0;
    for (int h=i+1 ; h<m ; h++){
        int lower_slice = apples[h][j];
        int upper_slice = apples[i][j] - lower_slice;
        
        if (upper_slice >= 1 and lower_slice >= k-1){
            ans = (ans % mod + solve(h, j, k-1, apples, dp) % mod) % mod;
        }
    }
    for (int v=j+1 ; v<n ; v++){
        int right_slice = apples[i][v];
        int left_slice = apples[i][j] - right_slice;
        
        if (left_slice >= 1 and right_slice >= k-1){
            ans = (ans % mod + solve(i, v, k-1, apples, dp) % mod) % mod;
        }
    }
    
    return dp[i][j][k] = ans % mod;
}

int ways(vector<string>& pizza, int k) {
    m = pizza.size();
    n = pizza[0].size();
    
    vector<vector<int>> apples(55, vector<int> (55, 0));
    
    for (int i=m-1 ; i>=0 ; i--){
        for (int j=n-1 ; j>=0 ; j--){
            apples[i][j] = apples[i][j+1];
            for (int l=i ; l<m ; l++){
                if (pizza[l][j] == 'A'){
                    apples[i][j]++;
                }
            }
        }
    }
    vector<vector<vector<int>>> dp(55, vector<vector<int>>(55, vector<int>(15, -1)));
    
    return solve(0, 0, k, apples, dp);
}
};