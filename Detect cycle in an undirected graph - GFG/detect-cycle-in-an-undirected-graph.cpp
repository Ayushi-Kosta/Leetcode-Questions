// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool cycle(int i, vector<bool> &vis, vector<int> adj[]){
        queue<pair<int, int>> q;
        vis[i]=1;
        q.push({i, -1});
        while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            for(auto x : adj[a]){
                if(!vis[x]){
                    vis[x]=1;
                    q.push({x, a});
                }
                else if(x!=b){
                    return 1;
                }
            }
        }
        return 0;
    }
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
         vector<bool> vis(n, 0);
       
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(cycle(i, vis, adj)) return 1;
            }
        }
        return 0;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends