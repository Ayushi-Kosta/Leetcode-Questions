class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> m;
        unordered_set<int> s;
        int t_s = trust.size();
        if(t_s == 0 and n==1) return n;
        if(t_s == 0 and n!=1) return -1;
        for(int i=0; i<t_s; i++){
            s.insert(trust[i][0]);
            m[trust[i][1]]++;
        }
        
        for(auto &x: m){
            if(x.second == n-1 and s.find(x.first)==s.end()){
                return x.first;
            }
        }
        return -1;
        
    }
};