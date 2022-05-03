class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        int n=nums.size(), i=0, j=n-1, end=-1, start=0, maxi=nums[0], mini=nums[n-1];
        for(i=1; i<n; i++){
            if(maxi>nums[i]){
                end=i;
            }
            else{
                maxi=nums[i];
            }
        }
        for(i=n-2; i>=0; i--){
            if(mini<nums[i]){
                start=i;
            }
            else{
                mini=nums[i];
            }
        }
        return (end-start+1);
    }
};