/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        int j;
        for (j = 1; j < nums.size(); j++)
        {
            if (nums[i] != nums[j]) // 由于是升序排列，所以只需要按顺序进行比较，留下与前一位不同的数字
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    };
};
// @lc code=end
