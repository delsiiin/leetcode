/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // 动态规划，滑动窗口
        int fin_max = -1e5; // 存放历史最大值
        int ins_max = -1e5; // 存放即时最大值
        for (int num : nums)
        {
            // 将当前元素与下一元素相加的和与下一元素做比，留下较大值作为即时最大值
            ins_max = max(ins_max + num, num);
            // 将当前历史最大值与即时最大值进行比较，较大值作为历史最大值
            fin_max = max(fin_max, ins_max);
        }
        return fin_max;
    }
};
// @lc code=end
