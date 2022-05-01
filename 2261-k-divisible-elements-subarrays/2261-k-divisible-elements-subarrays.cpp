class Solution {
public:        
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        set<vector<int>> s;
        for(int i=0; i<n; i++){
            int c=0;
            vector<int> v;
            for(int j=i; j<n; j++){
                v.push_back(nums[j]);
                if(nums[j]%p==0){
                    c++;
                }
                if(c>k){
                    break;
                }
                s.insert(v);
            }
        }
        return s.size();
    }
};