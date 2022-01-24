// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(vector<int> adj[], int start, int vis[], vector<int> &ans){
        queue<int> q;
        vis[start]=1;
        q.push(start);
        while(!q.empty()){
            int x = q.front(); q.pop();
            ans.push_back(x);
            for(int i : adj[x]){
                if(!vis[i]){
                    q.push(i);
                    vis[i]=1;    
                }
                
            }
        }
    }
    vector<int> bfsOfGraph(int n, vector<int> adj[]) {
        // Code here
        int vis[n];
        vector<int> ans;
        for(int i=0; i<n; i++)
            vis[i]=0;
            
        //for(int i=0; i<n; i++){
        //    if(!vis[i]){
                //bfs(adj, 0, vis, ans);
        //    }
        //}
        
        queue<int> q;
        vis[0]=1;
        q.push(0);
        while(!q.empty()){
            int x = q.front(); q.pop();
            ans.push_back(x);
            for(int i : adj[x]){
                if(!vis[i]){
                    q.push(i);
                    vis[i]=1;    
                }
                
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends