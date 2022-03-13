class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size(), area=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]){
                    int a = 0;
                    tr(i, j, a, grid);
                    area=max(area, a);    
                }
                
            }   
        }
        return area;
    }
    void tr(int i, int j, int &a, vector<vector<int>> &grid){
        int r = grid.size(), c = grid[0].size();

        if(i>=0 and i<r and j>=0 and j<c and grid[i][j]){
            a++;
            grid[i][j]=0;
            tr(i, j-1, a, grid);
            tr(i, j+1, a, grid);
            tr(i-1, j, a, grid);
            tr(i+1, j, a, grid);     
        }
       
        
    }
};