class Solution {
public:
//     static bool mycomp(vector<int> &a, vector<int> &b){
//         if(a[0]==b[0]){
//             return a[1]>b[1];
//         }
//         return (a[0]<b[0]);
        
//     }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size(), c=0, right=-1, left=-1;
        
        for(int i=0; i<n; i++){
            if(intervals[i][0]>left and intervals[i][1]>right){
                left = intervals[i][0];
                c++;
            }
            right = max(right, intervals[i][1]);
        }
        // for(int i=0; i<n; i++){
        //     cout<<intervals[i][0]<<" "<<intervals[i][1]<<" ";
        // }
        // cout<<"\n";
        return c;
    }
    
};