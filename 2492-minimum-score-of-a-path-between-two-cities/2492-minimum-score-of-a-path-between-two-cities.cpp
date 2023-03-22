class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n+1];
        for(int i=0; i<roads.size(); i++)
        {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        
        
        vector<int> vis(n+1, 0);
        queue<int> q;
        q.push(1);
        vis[1]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it: adj[node])
            {
                if(!vis[it.first])
                {
                    q.push(it.first);
                    vis[it.first]=1;
                }
            }
        }
            
        int mini_path = INT_MAX;
        for(int i=0; i<roads.size(); i++)
        {
            if(vis[roads[i][0]] and vis[roads[i][1]] and roads[i][2] < mini_path) mini_path = roads[i][2];
        }
        return mini_path;
    }
};