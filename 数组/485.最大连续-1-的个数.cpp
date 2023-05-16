/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        /* 快慢指针 */
        int slow = 0, fast = 0;
        int max = 0;
        while (fast < nums.size())
        {
            if (nums[fast] == 1)
            {
                slow++;
            }
            else
            {
                if (slow > max)
                {
                    max = slow;
                }
                slow = 0;
            }
            fast++;
        }
        if (slow > max)
        {
            max = slow;
        }
        return max;
    }
};
// @lc code=end
