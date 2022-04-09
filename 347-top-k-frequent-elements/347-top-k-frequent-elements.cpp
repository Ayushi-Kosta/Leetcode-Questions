class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> p;
        vector<pair<int, int>> w;
        int n = nums.size();
        priority_queue<pair<int, int>> o;
        map<int, int> m;
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        for(auto &x: m){
            o.push({x.second, x.first});
        }
        int i=k;
        while(i--){
            p.push_back(o.top().second);
            o.pop();
        }
        return p;
    }
};