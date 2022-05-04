class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size(), i=0, j=n-1, cou=0;
        unordered_map<int, int> m;
        while(i<n){
            if(m.find(k-nums[i])!=m.end()){
                cou++;
                m[k-nums[i]]--;
                if(m[k-nums[i]]==0){
                    m.erase(k-nums[i]);
                }
            }
            else{
                m[nums[i]]++;
            }
            i++;
        }
        return cou;
    }
};