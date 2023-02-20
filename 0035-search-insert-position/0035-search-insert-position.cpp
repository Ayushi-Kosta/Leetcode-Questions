class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0, h=n-1, m;
        while(l<=h){
            m=(l+(h-l)/2);
            if(nums[m]>target){
                h=m-1;
            }
            else if(nums[m]<target){
                l=m+1;
            }
            else{
                return m;
            }
        }
        if(nums[m]>target){
            return m;
        }
        else{
            return m+1;
        }
    }
};