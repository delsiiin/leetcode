/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        /* 常规解法，效率不高 */

        // vector<int> temp;
        // int i;
        // int len = nums.size();
        // for (i = 0; i < len; i++)
        // {
        //     if (nums[i] != 0)
        //     {
        //         temp.insert(temp.begin(), nums[i]);
        //         nums.erase(nums.begin() + i);
        //         i--;
        //         len--;
        //     }
        // }
        // for (int num : temp)
        // {
        //     nums.insert(nums.begin(), num);
        // }

        /* 使用双指针解法，高效 */

        // 右指针一直向右移动，遇到非零的数则与左指针的数互换，同时左指针右移一位
        int len = nums.size();
        int left = 0, right = 0;
        while (right < len)
        {
            if (nums[right] != 0)
            {
                swap(nums[right], nums[left]);
                left++;
            }
            right++;
        }
    }
};
// @lc code=end
