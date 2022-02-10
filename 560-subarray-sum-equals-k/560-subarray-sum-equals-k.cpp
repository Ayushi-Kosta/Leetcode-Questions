class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(), sum=0, count=0;
        unordered_map<int, int> s;
        for(int i=0; i<n; i++){
            sum+=(nums[i]);
            if((!s.empty() and s.find(sum-k)!=s.end())){
                count+=(s[sum-k]);
            }
            if(sum==k){
                count++;
            }
            s[sum]++;
        }
        return count;
    }
};