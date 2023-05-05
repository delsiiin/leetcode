/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        /* 迭代器begin、end返回的均为地址 */
        /* 使用if语句需要将所有情况均考虑进去，否则可能出现编译报错 */

        // sort(nums.begin(), nums.end());
        // int i = 0;
        // if (nums.size() == 1)
        // {
        //     return nums[0];
        // }
        // else
        // {
        //     while (i < nums.size())
        //     {
        //         if (nums[i] == nums[i + 1])
        //         {
        //             i = i + 2;
        //             if (i == nums.size() - 1)
        //             {
        //                 return nums[i];
        //             }
        //         }
        //         else
        //         {
        //             return nums[i];
        //         }
        //     }
        //     return 0;
        // }

        /* 使用抑或运算，对数组中每个元素进行依次抑或，最终得到落单元素 */
        int i;
        int res = nums[0];
        for (i = 0; i < nums.size() - 1; i++)
        {
            res ^= nums[i + 1];
        }
        return res;
    }
};
// @lc code=end
