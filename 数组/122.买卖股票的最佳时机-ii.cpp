/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int i;
        int sum = 0;
        for (i = 0; i < prices.size() - 1; i++)
        {
            if (prices[i + 1] > prices[i])
            {
                sum += prices[i + 1] - prices[i];
            }
        }
        return sum;
    }
};
// @lc code=end
