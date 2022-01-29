class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int m = 1, n=nums.size();
        int count=0;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                count++;
            }
            else{
                m*=nums[i];
            }
        }
        if(count==n){
            m=0;
        }
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                if(count>1){
                    nums[i]=0;
                }
                else{
                    nums[i]=m;
                }
            }
            else{
                if(count==0){
                    nums[i]=m/nums[i];
                }
                else{
                    nums[i]=0;
                }
            }
        }
        return nums;
    }
};