/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /* DFS */
    int step = 0;
    void helper(vector<int> &nums, int target, int sum, int index)
    {
        if (sum == target && index == nums.size())
        {
            step++;
        }
        else if (index < nums.size())
        {
            helper(nums, target, sum + nums[index], index + 1);
            helper(nums, target, sum - nums[index], index + 1);
        }
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        vector<int> temp = nums;
        helper(temp, target, 0, 0);
        return step;
    }
};
// @lc code=end
