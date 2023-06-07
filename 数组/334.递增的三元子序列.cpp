/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        // vector<int> leftMin(nums.size());
        // // 记录每个数对应的左边最小值
        // leftMin[0] = INT_MAX;
        // for (int i = 0; i < nums.size() - 1; i++)
        // {
        //     leftMin[i + 1] = min(leftMin[i], nums[i]);
        // }
        // vector<int> rightMax(nums.size());
        // // 记录每个数对应的右边最大值
        // rightMax[nums.size() - 1] = INT_MIN;
        // for (int j = nums.size() - 1; j > 0; j--)
        // {
        //     rightMax[j - 1] = max(rightMax[j], nums[j]);
        // }
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     // 遍历数组，若存在当前值大于左边最小值且小于右边最大值，则满足条件
        //     if (nums[i] > leftMin[i] && nums[i] < rightMax[i])
        //         return true;
        // }
        // return false;

        // 贪心算法
        int n = nums.size();
        if (n < 3)
        {
            return false;
        }
        int first = nums[0], second = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            int num = nums[i];
            if (num > second)
            {
                return true;
            }
            else if (num > first)
            {
                second = num;
            }
            else
            {
                first = num;
            }
        }
        return false;
    }
};
// @lc code=end
