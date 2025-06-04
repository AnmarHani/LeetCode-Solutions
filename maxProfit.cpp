class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0], bestProfit = -1;

        for(const int price : prices) {
            minPrice = min(minPrice, price);
            bestProfit = max(bestProfit, price - minPrice);
        }

        return bestProfit;
    }
};
