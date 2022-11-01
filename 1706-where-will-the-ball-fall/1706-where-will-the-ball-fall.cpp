class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& grid, int n, int m){
        if(i==m) return j;
        
        if(grid[i][j]==1){
            if(j==n-1 or grid[i][j+1]==-1){
                return -1;
            }
            else{
                return helper(i+1, j+1, grid, n, m);
            }
        }
        else{
            if(j==0 or grid[i][j-1]==1){
                return -1;
            }
            else{
                return helper(i+1, j-1, grid, n, m);
            }
        }
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        // four conditions : 
        // 1. if on 1 then if next is 1 then col+1 and row+1
        // 2. if on right upper and next cell is boundary or -1 then stucked
        // 3. if on -1 and if prev is 1 or boundary then stucked
        // 4. if on -1 and prev is -1 then col-1 and row+1
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            ans[i] = helper(0, i, grid, n, m);
        }
        return ans;
    }
};