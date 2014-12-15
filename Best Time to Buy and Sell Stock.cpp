class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n < 2)
            return 0;
        int valley = prices[0], peak = valley;
        int profit = 0;
        for (int i = 1; i < n; ++i)
        {
            if (prices[i] > peak)
            {
                peak = prices[i];
                profit = max(profit, peak - valley);
            }
            else if (prices[i] < valley)
            {
                valley = prices[i];
                peak = valley;
                
            }
        }
        return profit;
    }
};