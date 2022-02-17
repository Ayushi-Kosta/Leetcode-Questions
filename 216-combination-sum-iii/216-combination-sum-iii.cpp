class Solution {
public:
    void s(vector<int>& candidates, int target, vector<int> a, vector<vector<int>> &v, int         var, int k){
        if(target==0 and k==0){
            v.push_back(a);
            return ;
        }
        if(target<0){
            return ;
        }
        int n = candidates.size();
        for(int i=var; i<n; i++){
            a.push_back(candidates[i]);
            s(candidates, target-candidates[i], a, v, i+1, k-1);
            a.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> z = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> v;
        vector<int> a;
        s(z, n, a, v, 0, k);
        return v;
    }
};