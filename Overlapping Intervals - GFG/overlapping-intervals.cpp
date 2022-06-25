// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    static bool mysort(vector<int> &a, vector<int> &b){
        return a[0]<b[0];
    }
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         sort(intervals.begin(), intervals.end(), mysort);
         int i=0, n= intervals.size();
         vector<vector<int>> ans;
         while(i<n){
             int start=intervals[i][0], end=intervals[i][1];
             while(i<n-1 and end>=intervals[i+1][0]){
                 end=max(end, intervals[i+1][1]);
                 i++;
             }
             ans.push_back({start, end});
             i++;
             
         }
         return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends