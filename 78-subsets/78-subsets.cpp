class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums){
        int n = nums.size();
        vector<int> v;
        vector<vector<int>> ans;
        ans.push_back({});
        for(int i=0; i<n; i++){
            int n_ans = ans.size();
            for(int j=0; j<n_ans; j++){
                vector temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};