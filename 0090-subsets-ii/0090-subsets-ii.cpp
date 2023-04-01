class Solution {
public:

    void helper(vector<int>& nums, int i, int n, vector<int> cur, set<vector<int>>& m){
        if(i>=n){
            m.insert(cur);
            return ;
        } 
        helper(nums, i+1, n, cur, m);
        cur.push_back(nums[i]);
        helper(nums, i+1, n, cur, m);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        set<vector<int>> m;
        helper(nums, 0, n, cur, m);
        for(auto &x: m){
            ans.push_back(x);
        }
        return ans;
    }
};