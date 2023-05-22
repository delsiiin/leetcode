/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        // 动态规划，将求和为整数n的最少数量转换为：求和为n-j*j（j从1到根号n）中的最小值再加一
        vector<int> res(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int min = INT_MAX;
            for (int j = 1; j * j <= i; j++)
            {
                if (res[i - j * j] < min)
                    min = res[i - j * j];
            }
            res[i] = min + 1;
        }
        return res[n];
    }
};
// @lc code=end
