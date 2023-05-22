/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        /* 使用sort函数 */
        // sort(nums.begin(), nums.end());
        // return nums.front();

        // if (nums.front() <= nums.back())
        //     return nums.front();
        // else
        // {
        //     for (int i = 0; i < nums.size() - 1; i++)
        //     {
        //         if (nums[i] > nums[i + 1])
        //             return nums[i + 1];
        //     }
        // }
        // return -1;

        /* 二分查找 */
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return nums[left];
    }
};
// @lc code=end
