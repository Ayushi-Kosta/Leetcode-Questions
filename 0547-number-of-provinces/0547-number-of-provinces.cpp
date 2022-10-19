class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>&vis, int in){
        vis[in]=1;
        for(int j=0; j<isConnected[in].size(); j++){
            if(in!=j and isConnected[in][j] and vis[j]!=1){
                    dfs(isConnected, vis, j);
                }   
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // number of bfs call will give the number of connected components
        // mark 2 for visited
        vector<int> vis(isConnected.size(), 0);
        int count=0;
        for(int i=0; i<isConnected.size(); i++){
            if(vis[i]!=1){
                dfs(isConnected, vis, i);
                // cout<<i<<" "<<j<<"\n";
                count++;
            }
        }
        return count;   
    }
};