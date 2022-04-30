class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> m;
        int n = equations.size();
        for(int i=0; i<n; i++){
            m[equations[i][0]].insert(make_pair(equations[i][1], values[i]));
            m[equations[i][1]].insert(make_pair(equations[i][0], 1/values[i]));
        }
        vector<double> ans;
        for(auto &q: queries){
            unordered_set<string> str;
            double t = solve(q[0], q[1], m, str);
            if(t){
                ans.push_back(t);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
    double solve(string num, string den, unordered_map<string, unordered_map<string, double>> m, unordered_set<string> str){
        if(m[num].find(den)!=m[num].end()){
            return m[num][den];
        }
        
        for(auto &w: m[num]){
            if(str.find(w.first)==str.end()){
                str.insert(w.first);
                double h = solve(w.first, den, m, str);
                if(h){
                    return w.second*h;
                }
            }
            
        }
        return 0;
        
    }
};