class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            // Best price to buy before today
            minPrice = min(minPrice, price);

            // Profit if we sell today
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};