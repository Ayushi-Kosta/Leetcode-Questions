class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX, profit=0;
        for(int i=0; i<prices.size(); i++){
            profit = max(profit, prices[i]-mini);
            if(mini>prices[i]){
                mini=prices[i];
            }
        }
    return profit;
    }
};