/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        /* 快慢指针解决 */
        int slow = 0, fast = 0;
        while (fast < nums.size())
        {
            if (nums[fast] != val)
                nums[slow++] = nums[fast];
            fast++;
        }
        return slow;
    }
};
// @lc code=end
