class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i=0; i<n; i++){
            m[nums[i]]++;
            if(m[nums[i]] > n/2){
                return nums[i];
            }
        }
        return -1;
    }
};