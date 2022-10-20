class Solution {
public:
    // void bfs()
    int orangesRotting(vector<vector<int>>& grid) {
        // we will call dfs or bfs at every rotten orange and call the bfs/dfs at every fresh orange which is 4 diagonally adjacent to it.
        
        // we will store the time also in the queue
        // and also store the time {{i,j},time}
        
        // so call bfs/dfs and rotten the oranges coming in the path way
        vector<vector<int>>vis = grid;
        int row = grid.size(), col = grid[0].size();
        int t=0, max_time=0;
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},t});
                    vis[i][j]=3;
                }
                else{
                    vis[i][j]=0;
                }
            }   
        }
        while(!q.empty()){
            int i = q.front().first.first, j = q.front().first.second, time = q.front().second;
            // call on the four adjacents
            //         (i-1,j)
            // (i,j-1)  (i,j)  (i,j+1)
            //         (i+1,j)
            q.pop();
            if(i-1>=0 and i-1<row and grid[i-1][j]==1 and vis[i-1][j]!=3){
                vis[i-1][j]=3;
                grid[i-1][j]=2;
                q.push({{i-1,j},time+1});
            }
            if(j-1>=0 and j-1<col and grid[i][j-1]==1 and vis[i][j-1]!=3){
                vis[i][j-1]=3;
                grid[i][j-1]=2;                
                q.push({{i,j-1},time+1});
            }
            if(j+1>=0 and j+1<col and grid[i][j+1]==1 and vis[i][j+1]!=3){
                vis[i][j+1]=3;
                grid[i][j+1]=2;
                q.push({{i,j+1},time+1});
            }
            if(i+1>=0 and i+1<row and grid[i+1][j]==1 and vis[i+1][j]!=3){
                vis[i+1][j]=3;
                grid[i+1][j]=2;
                q.push({{i+1,j},time+1});
            }  
            max_time = max(time, max_time);
        }
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==1){
                   return -1;
                }
            }   
        }
        
        return max_time;        
    }
};