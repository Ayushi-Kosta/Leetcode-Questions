class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int d = -1, n=nums.size();
        for(int i=0; i<n; i++){
            int val = abs(nums[i]);
            if(nums[val]>=0){
                nums[val]=-nums[val];
            }
            else{
                d=val;
                return d;
            }
        }
        return 0;
    }
};