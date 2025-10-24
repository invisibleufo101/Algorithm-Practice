class Solution {
public:
    int maxProfit(vector<int>& prices) {

        vector<int>v;
        int curPrice = prices[0];
        int profit = 0;
        // Think like a day trader and assume that selling as soon as the price rises is the most optimal solution
        for (int i=1; i<prices.size(); i++) {
            if (prices[i] > curPrice) {
                profit += (prices[i] - curPrice);    
            } 

            curPrice = prices[i];
        }

        return profit;    
    }
};
