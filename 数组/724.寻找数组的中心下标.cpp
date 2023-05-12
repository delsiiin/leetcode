/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        /* 直接判断前缀和与后缀和是否相等 */
        // int sum_l, sum_r;
        // int len = nums.size();
        // int i, j, k;
        // for (i = 0; i < len; i++)
        // {
        //     sum_l = 0;
        //     sum_r = 0;
        //     for (j = 0; j < i; j++)
        //     {
        //         sum_l += nums[j];
        //     }

        //     for (k = i + 1; k < len; k++)
        //     {
        //         sum_r += nums[k];
        //     }
        //     if (sum_l == sum_r)
        //         return i;
        // }
        // return -1;

        /* 只需要判断前缀和的2倍加上中心元素是否等于整体和 */
        int sum = 0;
        int pre_sum = 0;
        for (int num : nums)
        {
            sum += num;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (pre_sum * 2 + nums[i] == sum)
                return i;
            pre_sum += nums[i];
        }
        return -1;
    }
};
// @lc code=end
