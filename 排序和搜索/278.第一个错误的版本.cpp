/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        // 二分查找
        int left = 1, right = n;
        while (left <= right)
        {
            int mid = left + (right - left) / 2; // 将(left + right) / 2拆分为left + (right - left) / 2，防止整数溢出
            if (!isBadVersion(mid))
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};
// @lc code=end
