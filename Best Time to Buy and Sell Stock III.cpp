class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = (int)prices.size();
        if (n == 0)
            return 0;
        vector<int> profitBefore(n, 0), profitAfter(n, 0);
        int lowest = prices[0], highest = prices[n - 1], result = 0;
        for (int i = 1; i < n; ++i)
        {
            lowest = min(lowest, prices[i]);
            profitBefore[i] = max(profitBefore[i - 1], prices[i] - lowest);
        }
        for (int i = n - 2; i >= 0; --i)
        {
            highest = max(highest, prices[i]);
            profitAfter[i] = max(profitAfter[i + 1], highest - prices[i]);
            result = max(result, profitAfter[i] + profitBefore[i]);
        }
        return result;
    }
};