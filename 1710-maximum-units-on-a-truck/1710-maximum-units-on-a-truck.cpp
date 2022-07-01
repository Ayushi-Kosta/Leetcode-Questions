class Solution {
public:
    static bool mysort(vector<int> &a, vector<int> &b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), mysort);
        int boxes=0, i=0, n=boxTypes.size(), units=0;
        while(i<n and boxes+boxTypes[i][0]<truckSize){
            boxes+=boxTypes[i][0];
            units+=(boxTypes[i][0]*boxTypes[i][1]);
            i++;
            // cout<<boxes<<" ";
        }
        if(i<=n-1 and boxes>0) units+=((truckSize-boxes)*boxTypes[i][1]);
        return units;
    }
};