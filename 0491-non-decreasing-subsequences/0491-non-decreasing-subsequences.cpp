class Solution {
public:
    vector<int> helper(set<vector<int>> &ans, vector<int> v, vector<int>& nums, int i){
        int n = nums.size();
        if(i>=n) return v;
        int j = i;
            if(v[v.size()-1] <= nums[j]){
                v.push_back(nums[i]);
                vector<int> a = helper(ans, v, nums, j+1);
                if(a.size()>1) ans.insert(a);
                v.pop_back();
                
            }
                vector<int> a = helper(ans, v, nums, j+1);
                if(a.size()>1) ans.insert(a);
        return v;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans;
        for(int i=0; i<n-1; i++){
            vector<int> temp = {nums[i]};
            vector<int> b = helper(ans, temp, nums, i+1);
        }
        vector<vector<int>> anns;
        for(auto &x: ans){
            anns.push_back(x);
        }
        return anns;
    }
};