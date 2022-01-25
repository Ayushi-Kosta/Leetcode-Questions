class Solution {
public:
    static bool mycomp(pair<int,int> &a, pair<int, int> &b){
        return a.first>b.first;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        vector<pair<int, int>> v;
        vector<int> ans;
        for(auto x: m){
            v.push_back({x.second, x.first});
        }
        sort(v.begin(), v.end(), mycomp);
        for(int i=0; i<k; i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};