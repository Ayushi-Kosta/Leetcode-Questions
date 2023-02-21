class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i=0, n=nums.size();
        int l=0, h=n-1;
        while(l<h){
            int mid = (l+h)/2;
            if(mid%2!=0){
                mid--;
            }
            if(mid>0 and mid<n and nums[mid]!=nums[mid-1] and nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if(mid<n-1 and nums[mid]==nums[mid+1]){
                l=mid+2;
            }
            else{ 
                h=mid-2;
            }
            
        }
        return nums[l];
    }
};