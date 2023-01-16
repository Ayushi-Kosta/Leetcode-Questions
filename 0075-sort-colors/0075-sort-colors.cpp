class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size(), start_1=0, start_2=n-1, mov=0;
        
        while(mov<n and mov<=start_2){
            if(nums[mov]==1){
                mov++;
            }
            else if(nums[mov]==0){
                swap(nums[mov++], nums[start_1++]);
            }
            else{
                swap(nums[start_2--], nums[mov]);
            }
        }
        
    }
};