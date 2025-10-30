class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int curPrice = prices[0];
        int profit = 0;
        for (int i=1; i<prices.size(); i++) {
            curPrice = min(curPrice, prices[i]);
            profit = max(profit, prices[i] - curPrice);
        }

        return profit;
    }
};
