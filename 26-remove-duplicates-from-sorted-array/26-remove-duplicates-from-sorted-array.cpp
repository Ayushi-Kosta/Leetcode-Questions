class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, n=nums.size();
        for(int j =0; j<n; j++){
            if(nums[j]>nums[i-1]){
                nums[i]=nums[j];
                i++;
            }
        }
        return i;
    }
};