class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int r=points[0][1]; //right end of first balloon
        int ans=1;
        for(auto x: points){
            if(r>=x[0]){
                r=min(r, x[1]);
            }
            else{
                ans++;
                r=x[1];
            }
        }
        return ans;
    }
};