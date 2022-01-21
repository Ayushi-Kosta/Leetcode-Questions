class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();
        int total_gas = 0, curr=0, ans=0;
        for(int i=0; i<n; i++){
            total_gas+=(gas[i]-cost[i]);
            curr+=(gas[i]-cost[i]);
            if(curr<0){
                curr=0;
                ans=i+1;
            }
        }
        return (total_gas<0)? -1: ans;

    }
};