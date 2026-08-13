class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int profit{};
        int size = prices.size();

        for (int i{size - 1}; i > 0; --i) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};