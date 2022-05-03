class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        int n=nums.size(), i=0, j=n-1;
        while(i<n and nums[i]==v[i]){
            i++;
        }
        while(j>=0 and nums[j]==v[j]){
            j--;
        }
        // cout<<i<<" "<<j<<" \ ";
        if(i==n and j==-1) return 0;
        return (j-i+1);
    }
};