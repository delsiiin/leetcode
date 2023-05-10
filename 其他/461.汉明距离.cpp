/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
#include <queue>
#include <iostream>
using namespace std;

class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        if (x < y)
        {
            return hammingDistance(y, x);
        }
        queue<int> Qx;
        int ans = 0;
        while (x)
        {
            Qx.push(x % 2);
            x = x / 2;
        }
        while (y)
        {
            if (Qx.front() != y % 2)
                ans++;
            Qx.pop();
            y = y / 2;
        }
        while (!Qx.empty())
        {
            if (Qx.front() != 0)
                ans++;
            Qx.pop();
        }
        return ans;
    }
};
// @lc code=end
