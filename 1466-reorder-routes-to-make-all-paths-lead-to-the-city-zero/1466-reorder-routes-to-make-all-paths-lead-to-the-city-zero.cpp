class Solution {
public:
int dfs(vector<vector<int>> &al, vector<bool> &vis, int from) {
    auto change = 0;
    vis[from] = true;
    for (auto to : al[from])
        if (!vis[abs(to)]) change += dfs(al, vis, abs(to)) + (to > 0);
    return change;        
}
int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<int>> al(n);
    for (auto &c : connections) {
        al[c[0]].push_back(c[1]);
        al[c[1]].push_back(-c[0]);
    }
    vector<bool> vis(n,0);
    return dfs(al, vis, 0);
}
};