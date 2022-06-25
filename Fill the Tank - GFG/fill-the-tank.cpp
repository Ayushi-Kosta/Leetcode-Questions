// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {

public:
// bool possible = true;
// long long limit=1e18;
//     long long dfs(vector<vector<int>> adj, int N, vector<bool> &vis, int *Cap, int S){
//         long long supply=0, branches=0;
//         vis[S]=1;
//         if(possible==false) return -1;
//         for(auto &adjacent:adj[S]){
//             if(vis[adjacent]==0){
//                 branches++;
//                 supply=max(supply, dfs(adj, N, vis, Cap, adjacent));  
                
//                 if(supply*branches>limit){
//                     possible=false;
//                     return -1;
//                 }
//             } 
//         }
//         return Cap[S-1]+supply*branches;
        
//     }
//     long long minimum_amount(vector<vector<int>> &Edges, int N, int S, int *Cap){
//       // Code here
//       vector<vector<int>> adj(N+1);
//       vector<bool> vis(N+1, 0);
//       for(auto &e : Edges){
//           int u = e[0], v = e[1];
//           adj[u].push_back(v);
//           adj[v].push_back(u);
//       }
//       long long temp = dfs(adj, N, vis, Cap, S);
//       if(possible==false or temp>limit){
//           return -1;
//       }
//       else return temp;
       
//     }

static const int N = 1e5 + 1;
	int n ;
	unordered_map<int, vector<int>> gr;
	bool flg = 0;

	long long dfs(int curr, int par, int* cap) {
		long long ans = 0;
		long long children = 0;
		for (int x : gr[curr]) {
			if (x != par) {
				children++;
				long long re = dfs(x, curr, cap);
				if (re > 1e18) {
					flg = 1;
				}
				if (flg) return ans;
				ans = max(ans, re);
			}
		}
		long long res = cap[curr - 1];
		res += (children * ans);
		return res;
	}

	long long minimum_amount(vector<vector<int>> &Edges, int n, int start, int *cap) {
		// Code here
		this->n = n;
		// build graph
		for (vector<int> edge : Edges) {
			int s = edge[0], e = edge[1];
			gr[s].push_back(e);
			gr[e].push_back(s);
		}
		long long res = dfs(start, -1, cap);
		if (res > 1e18 || flg) return -1;
		return res;
	}
};

// { Driver Code Starts.


int main()
 {
	int T;
	cin>> T;
	while (T--)
	{
	    int num, start;
	    cin>>num>>start;
	    int cap[num];
	    for(int i = 0; i<num; i++)
	        cin>>cap[i];
	    
	    vector<vector<int>> Edges(num-1);
	    for(int i=1;i < num;i++){
	        int u, v; cin >> u >> v;
	        Edges[i-1].push_back(u);
	        Edges[i-1].push_back(v);
	    }
	    
	    
    	Solution obj;
	    long long ans = obj.minimum_amount(Edges, num, start, cap);
	    cout << ans << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends