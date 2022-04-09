class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> p;
        vector<pair<int, int>> w;
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> o;
        map<int, int> m;
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        for(auto &x: m){
            o.push({x.second, x.first});
            if(o.size()>k) o.pop();
        }
        int i=k;
        while(i--){
            p.push_back(o.top().second);
            o.pop();
        }
        return p;
    }
    
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int, int> mp;
    //     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //     for(auto &i: nums) mp[i]++;
    //     for(auto &i: mp) {
    //         pq.push({i.second, i.first});
    //         if(pq.size()>k) pq.pop();
    //     }
    //     vector<int> ans;
    //     while(!pq.empty()) {
    //         ans.push_back(pq.top().second);
    //         pq.pop();
    //     }
    //     return ans;
    // }
};