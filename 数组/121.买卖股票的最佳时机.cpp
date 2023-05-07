/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        /* 暴力破解会超时 */
        // int Max = 0;
        // int i, j;
        // int buy;
        // int len = prices.size();
        // vector<int> temp;
        // for (i = 0; i < len - 1; i++)
        // {
        //     // buy = prices.front();
        //     // prices.erase(prices.begin());
        //     // temp = prices;
        //     // sort(temp.begin(), temp.end());
        //     // if (temp.back() - buy >= max)
        //     // {
        //     //     max = temp.back() - buy;
        //     // }

        //     for (j = i + 1; j < len; j++)
        //     {
        //         // if (prices[j] - prices[i] >= max)
        //         //     max = prices[j] - prices[i];
        //         Max = max(Max, prices[j] - prices[i]);
        //     }
        // }
        // return Max;

        int Min = 1e5;
        int Max = 0;
        for (int price : prices)
        {
            Max = max(Max, price - Min);
            Min = min(price, Min);
        }
        return Max;
    }
};
// @lc code=end
