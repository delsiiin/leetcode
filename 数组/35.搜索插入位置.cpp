/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        /* 暴力破解不满足时间复杂度的要求 */
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (nums[i] >= target)
        //     {
        //         return i;
        //     }
        // }
        // return nums.size();

        /* 二分查找 */
        int left = 0, right = nums.size() - 1;
        int mid;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        // 找不到则返回left，即为插入位置索引
        return left;
    }
};
// @lc code=end
