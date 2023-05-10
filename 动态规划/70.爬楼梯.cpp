/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        /* 递归的重复计算过多，会超时（可考虑将对应的值存进map中） */
        // if (n == 1 || n == 0)
        //     return 1;
        // return climbStairs(n - 1) + climbStairs(n - 2);

        int x = 0, y = 1;
        int sum;
        while (n)
        {
            sum = x + y;
            x = y;
            y = sum;
            n--;
        }
        return sum;
    }
};
// @lc code=end
