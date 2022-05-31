class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> se;
        int n = 1<<k, n_s=s.size();
        // cout<<n;
        for(int i=0; i<=n_s-k; i++){
            se.insert(s.substr(i, k));
        }
        if(se.size()==n){
            return 1;
        }
        return 0;
    }
};