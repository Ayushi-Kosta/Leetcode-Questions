class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size(), mini=-1, maxi=-1, invalid=-1;
        long long res=0;
        for(int i=0; i<n; i++){
            if(nums[i]==minK){
                mini=i;
            }
            if(nums[i]==maxK){
                maxi=i;
            }
            if(nums[i]<minK or nums[i]>maxK){
                invalid=i;
            }
            res+=max(0, min(mini,maxi)-invalid);
        }
        return res;
    }
};