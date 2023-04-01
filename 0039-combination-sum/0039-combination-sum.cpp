class Solution {
public:
    void helper(vector<int>& nums, int target, set<vector<int>> & ans, vector<int> cur, int cur_sum, int i){
        if(i>=nums.size()) return ;
        if(cur_sum == target){
            ans.insert(cur);
            return ;
        }
        if(cur_sum+nums[i]<=target){
            helper(nums, target, ans, cur, cur_sum, i+1);
            cur.push_back(nums[i]);
            helper(nums, target, ans, cur, cur_sum+nums[i], i+1);
            helper(nums, target, ans, cur, cur_sum+nums[i], i);
        }
                
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        set<vector<int>> v;
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        helper(candidates, target, v, cur, 0, 0);
        for(auto &x: v){
            ans.push_back(x);
        }
        return ans;
    }
};