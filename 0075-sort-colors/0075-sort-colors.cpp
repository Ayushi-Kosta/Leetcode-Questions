class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size(), start_0=0, mid_unknown=0, start_2_minus_1=n-1;
        while(start_2_minus_1>=mid_unknown){
            if(nums[mid_unknown]==0){
                swap(nums[start_0], nums[mid_unknown]);
                start_0++;
                mid_unknown++;
            }
            else if(nums[mid_unknown]==1){
                mid_unknown++;
            }
            else{
                swap(nums[start_2_minus_1], nums[mid_unknown]);
                start_2_minus_1--;              
            }
        }
    }
};