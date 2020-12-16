class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int previousPrice = -1;
        for (auto &price: prices) {
            if (previousPrice == -1) {
                previousPrice = price;       
            } else {
                if (price > previousPrice) {
                    profit  = profit + price - previousPrice;
                }
                previousPrice = price;
            }
        }
        return profit;
    }
};