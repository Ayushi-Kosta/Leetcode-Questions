class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> m;
        int n = nums.size();
        int i=0, j=0, sum=0, ans=0;
        while(j<n){
            if(m.find(nums[j])==m.end()){
                m.insert(nums[j]);
                sum+=nums[j];
                j++;
            }
            else{
                while(i<j and m.find(nums[j])!=m.end()){
                    m.erase(nums[i]);                    
                    sum-=nums[i];
                    i++;
                }
            }
            
            ans=max(sum, ans);
        }
        return ans;
    }
};