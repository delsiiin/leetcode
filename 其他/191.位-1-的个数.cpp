/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n)
        {
            // if (n % 2 == 1)
            // {
            //     count++;
            // }
            // n = n / 2;

            // 效率更高，与小一的数按位与能将n的二进制表示中从左往右最后一个1变为0
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};
// @lc code=end
