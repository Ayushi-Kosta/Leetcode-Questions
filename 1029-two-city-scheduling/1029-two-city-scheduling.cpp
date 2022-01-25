class Solution {
public:
    static bool mycomp(vector<int> &a, vector<int> &b){
        return (a[0]-a[1])<(b[0]-b[1]);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int> a, b;
        int n=costs.size();
        sort(costs.begin(), costs.end(), mycomp);
        int ans=0, i=0;
        n=n/2;
        while(i<n){
            ans+=(costs[i][0] + costs[i+n][1]);
                i++;
        }
        return ans;
        
    }
};