class Solution {
public:
    int dp[501][501] = {};
    int dfs(vector<int>& sat, int p, int t) {
        if (p >= sat.size()) return 0;
        if (dp[p][t]) return dp[p][t];       
        return dp[p][t] = max(dfs(sat,p + 1,t), sat[p]*t + dfs(sat,p+1,t+1));
    }
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(), sat.end());
        return dfs(sat, 0, 1);
    }
};