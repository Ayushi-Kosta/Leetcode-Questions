class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size(), temp=INT_MAX;
        vector<int> mini, maxi;
        // calculate min in left for each ele 
        for(int i=0; i<n; i++){
            mini.push_back(temp);
            if(nums[i]<temp){
                temp=nums[i];
                
            }
        }
        temp=INT_MIN;
        // calculate max in right for each ele
        for(int i=n-1; i>=0; i--){
            maxi.push_back(temp);
            if(nums[i]>temp){
                temp=nums[i];
                
            }
        }
        reverse(maxi.begin(), maxi.end());
        
        for(int i=0; i<n; i++){
            if(mini[i]<nums[i] and maxi[i]>nums[i] and mini[i]<maxi[i] and mini[i]!=INT_MAX and maxi[i]!=INT_MIN){
                // cout<<mini[i]<<" "<<nums[i]<<" "<<maxi[i]<<"\n";
                return true;
            }
        }
        return false;
    }
};