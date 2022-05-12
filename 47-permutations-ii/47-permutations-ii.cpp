class Solution {
public:
    void helper(vector<vector<int>> &ans, vector<int> v, unordered_map<int, int> m, int n){
        if(v.size()==n){
            ans.push_back(v);
            return ;
        }
        for(auto &x : m){
            if(x.second==0) continue;
            x.second--;
            v.push_back(x.first);
            helper(ans, v, m, n);
            v.pop_back();
            m[x.first]++;
        }
        return;
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    // we will maintain the frequency of elements and will try to include it and reduce he frequency and then we will recursively try to find the permutations of remaining characters
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> v;
        unordered_map<int, int> m;
        for(auto &x: nums){
            m[x]++;
        }
        helper(ans, v, m, n);
        return ans;
    }
};