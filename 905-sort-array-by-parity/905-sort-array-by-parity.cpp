class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> e, o;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]%2==0){
                e.push_back(nums[i]);
            }
            else{
                o.push_back(nums[i]);
            }
        }
        int i=0;
        for(auto &s: e){
            nums[i++]=s;
        }
        for(auto &s: o){
            nums[i++]=s;
        }
        return nums;
    }
};