class Solution {
public:
    void s(vector<int>& candidates, int target, vector<int> a, vector<vector<int>> &v, int var){
        if(target==0){
            v.push_back(a);
            return ;
        }
        if(target<0){
            return ;
        }
        int n = candidates.size();
        for(int i=var; i<n; i++){
            a.push_back(candidates[i]);
            s(candidates, target-candidates[i], a, v, i);
            a.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> a;
        s(candidates, target, a, v, 0);
        return v;
    }
};