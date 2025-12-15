// You are given an integer array prices where prices[i] is the price of NeetCoin on the ith day.
// You may choose a single day to buy one NeetCoin and choose a different day in the future to sell it.
// Return the maximum profit you can achieve. You may choose to not make any transactions,
//  in which case the profit would be 0.
// You should aim for a solution with O(n) time and O(1) space, where n is the size of the input array.

#include <vector>

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        if (prices.size() == 1)
            return 0;

        int minPrice = prices[0];

        int maxProfit{0};

        for (size_t i{1}; i < prices.size(); ++i)
        {
            if (prices[i - 1] < minPrice)
            {
                minPrice = prices[i - 1];
            }
            int profit = prices[i] - minPrice;

            if (profit > maxProfit)
            {
                maxProfit = profit;
            }
        }

        return maxProfit;
    }
};
