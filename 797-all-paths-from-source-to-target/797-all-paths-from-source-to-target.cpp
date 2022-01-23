class Solution {
public:
    void dfs(vector<vector<int>> &ans, vector<int> &a, vector<vector<int>> &graph, int start){
        a.push_back(start);
            if(start==graph.size()-1){
                ans.push_back(a);
            }
            else{
                for(auto x: graph[start]){
                    dfs(ans, a, graph, x);    
                }                
            }            
        a.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        //apply dp on reverse topo
        vector<int> v;
        vector<vector<int>> ans;
        dfs(ans, v, graph, 0);
        return ans;
    }
};