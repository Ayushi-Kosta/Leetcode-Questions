class Solution {
public:
    void helper(vector<vector<int>> &ans, vector<int> v, int i, vector<int> &nums, int n){
        if(i>=n){
            ans.push_back(v);
            return;
        }
        helper(ans, v, i+1, nums, n);
        v.push_back(nums[i]);
        helper(ans, v, i+1, nums, n);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        int n=nums.size(), i=0;
        helper(ans, v, i, nums, n);
        return ans;
    }
};