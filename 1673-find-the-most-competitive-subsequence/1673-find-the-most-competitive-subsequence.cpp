class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        int to_delete = n-k;
        vector<int> s;
        for(int i=0; i<n; i++){
            while(!s.empty() and nums[i]<s.back() and to_delete>0){
                s.pop_back();
                to_delete--;
            }
            s.push_back(nums[i]);
        }
        return vector<int>(s.begin(), s.begin()+k);
    }
};