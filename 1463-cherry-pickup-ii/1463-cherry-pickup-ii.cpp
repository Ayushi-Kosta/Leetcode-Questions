class Solution {
public:
     int dp[100][100][100];
    
    int solve(int x1,int y1, int x2, int y2, int n, int m, vector<vector<int>> &grid) {
        
        // if one of the robot is out of bound.
        if(x1 < 0 || x1 >= n || x2 < 0 || x2 >= n || y1 < 0 || y1 >= m || y2 < 0 || y2 >= m) {
            return 0;
        }
        
        if(dp[x1][y1][y2] != -1) return dp[x1][y1][y2];
        
        
        int maxRes = max({
        // r1 down
        solve(x1+1, y1, x2+1, y2, n, m, grid),
        solve(x1+1, y1, x2+1, y2-1, n, m, grid),
        solve(x1+1, y1, x2+1, y2+1, n, m, grid),
        // r1 down-left
        solve(x1+1, y1-1, x2+1, y2, n, m, grid),
        solve(x1+1, y1-1, x2+1, y2-1, n, m, grid),
        solve(x1+1, y1-1, x2+1, y2+1, n, m, grid),
        // r1 down-right
        solve(x1+1, y1+1, x2+1, y2, n, m, grid),
        solve(x1+1, y1+1, x2+1, y2-1, n, m, grid),
        solve(x1+1, y1+1, x2+1, y2+1, n, m, grid)
        
        });
        
        // we actually don't need to check for x we are doing down for both the robots.
        if(x1 == x2 && y1 == y2) {
            return dp[x1][y1][y2] = grid[x1][y1] + maxRes;
        }
        
        return dp[x1][y1][y2] = grid[x1][y1] + grid[x2][y2] + maxRes;
        
        
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        // i+1, j-1 => down and left
        // i+1, j => down
        // i+1, j+1, down and right
        
        memset(dp, -1, sizeof(dp));
        
        int n = grid.size();
        int m = grid[0].size();
        
        return solve(0, 0, 0, m-1, n, m, grid);
    }
};