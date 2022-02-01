class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int min_price=INT_MAX;
        int n = prices.size();
        for(int i=0; i<n; i++){
            if(min_price>prices[i]){
                min_price=prices[i];
            }
            profit=max(profit, max(0, prices[i]-min_price));
        }
        return profit;
    }
};