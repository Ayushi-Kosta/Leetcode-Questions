class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> e, o;
        int n = nums.size(), i=0, j=n-1;
        while(i<j and j>=0 and i<n){
            if(nums[i]%2==1 and nums[j]%2==0){
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            if(nums[i]%2==0) i++;
            if(nums[j]%2==1) j--;
        }
        return nums;
    }
};