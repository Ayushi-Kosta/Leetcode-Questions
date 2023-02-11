class Solution {
public:
vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<int> res(n, -1), visit1(n, 0), visit2(n, 0);
        vector<vector<pair<int, int>>> edg(n);
    
        for(auto &a : red_edges) 
            edg[a[0]].push_back({a[1], 1});
        for(auto &a : blue_edges) 
            edg[a[0]].push_back({a[1], 2});
    
    
        res[0] = 0;
        int layer = 0;
    
        queue<pair<int, int>> q;
        q.push({0, 1});
        q.push({0, 2});
        while(!q.empty()) {
            int len = q.size();
            ++layer;
            for(int k=0; k<len; ++k) {
                auto t = q.front();
                q.pop();
                if(t.second == 1) visit1[t.first] = 1;
                else visit2[t.first] = 1;
                
                for(auto &a : edg[t.first]) {
                    if(t.second == 1 && (visit2[a.first] || a.second==1)) 
                        continue;
                    if(t.second == 2 && (visit1[a.first] || a.second==2)) 
                        continue;
                    
                    q.push(a);                      
                    if(res[a.first] == -1) res[a.first] = layer;
                }
            }
        }
        return res;
    }
};