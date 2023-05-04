/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int i;
        i = 0;
        int j = 0;
        int *prof = new int[prices.size() - 1]();
        int count = 0;
        // 贪心算法：只考虑最好的情况，即只考虑有增长的情况，只要后一天比前一天多，就进行买卖--只计算上升区间的高度和
        for (i = 0; i < prices.size() - 1; i++)
        {
            prof[count++] = prices[i + 1] - prices[i];
        }
        int max = 0;
        for (i = 0; i < count; i++)
        {
            if (prof[i] >= 0)
            {
                max += prof[i];
            }
        }
        delete[] prof;
        return max;
    }
};

// @lc code=end
