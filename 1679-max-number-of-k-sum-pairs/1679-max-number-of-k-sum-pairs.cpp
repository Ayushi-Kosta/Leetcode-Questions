class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size(), i=0, j=n-1, cou=0;
        while(i<j){
            if(nums[i]+nums[j]==k){
                i++;
                j--;
                cou++;
            }
            else if(nums[i]+nums[j]>k){
                j--;
            }
            else{
                i++;
            }
        }
        return cou;
    }
};