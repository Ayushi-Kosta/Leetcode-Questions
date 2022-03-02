class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        //checking if its a triangle or not
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        for(int i=2; i<n; i++){
            if(nums[i]+nums[i-1]>nums[i-2]){
                return nums[i]+nums[i-1]+nums[i-2];
            }
        }
        return 0;
        
    }
};