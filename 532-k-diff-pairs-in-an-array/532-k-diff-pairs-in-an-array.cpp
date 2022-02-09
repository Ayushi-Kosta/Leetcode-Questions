class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> s;
        int ans=0, n=nums.size();
        for(int i=0; i<n; i++){
           s[nums[i]]++;
        }
        for(auto x: s){
           if((k>0 and s.find(x.first+k)!=s.end()) or (k==0 and x.second>1)) {
               ans++;
           }
        }
        return ans;
    }
};