class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int n=trips.size();
        vector<int> a(1001, 0);
        
        for(int i=0; i<trips.size(); i++){
            a[trips[i][1]]+=trips[i][0];
            a[trips[i][2]]-=trips[i][0];
        }
        int c=0;
        for(int i=0; i<=1000; i++){
            c+=a[i];
            if(c>capacity){
                return 0;
            }
        }
        return 1;
    }
};