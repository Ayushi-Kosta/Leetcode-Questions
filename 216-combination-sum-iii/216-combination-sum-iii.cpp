class Solution {
public:
    void s(vector<vector<int>> &v, vector<int> a, vector<int> b, int k, int n, int iterator){
        int n_b = b.size();
        if(n==0 and k==0){
            v.push_back(a);
            return;
        }
        if(n<0){
            return;
        }
        for(int i=iterator; i<n_b; i++){
            a.push_back(b[i]);
            s(v, a, b, k-1, n-b[i], i+1);
            a.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> v;
        vector<int> a, b={1, 2, 3, 4, 5, 6, 7, 8, 9};
        int iterator=0;
        s(v, a, b, k, n, iterator);
        return v;
    }
};