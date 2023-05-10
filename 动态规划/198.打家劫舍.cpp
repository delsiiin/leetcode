/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int len = nums.size();
        // int pro_take = max(nums.front(), nums.back());
        // int pro_min = nums.front();
        int pro_take, pro_pre, pro_drop;
        int i;
        if (len == 1)
            return nums.front();
        pro_drop = max(nums[0], nums[1]);
        pro_pre = nums.front();
        if (len == 2)
            return pro_drop;
        for (i = 2; i < len; i++)
        {
            pro_take = nums[i] + pro_pre;       // 如果偷窃当前房屋，利润=当前房屋金额+到上上个房屋偷窃的总金额
                                                // 不偷窃当前房屋，则利润=到上个房屋偷窃的总金额
            pro_pre = pro_drop;                 // 更新到上上个房屋偷窃的总金额
            pro_drop = max(pro_drop, pro_take); // 判断是否偷窃当前房屋，将对应的两种情况的利润进行比较
        }
        return pro_drop;
    }
};
// @lc code=end
