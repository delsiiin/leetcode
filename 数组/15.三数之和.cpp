/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        // 对乱序先排序，变成升序数组
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            // 如果当前数与前一个数相同，则跳过
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            // 通过双指针缩短遍历时间
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] > -nums[i])
                    right--;
                else if (nums[left] + nums[right] < -nums[i])
                    left++;
                else
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    // 确保第二三个数不会重复
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
        }
        return res;
    }
};
// @lc code=end
