/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> t; // 记录当前数字是否选择（选或者不选）
    vector<vector<int>> res;
    void dfs(int cur, vector<int> nums)
    {
        if (cur == nums.size()) // 当前指针遍历完数组则返回
        {
            res.push_back(t);
            return;
        }
        // 将当前元素加入数组t
        t.push_back(nums[cur]);
        dfs(cur + 1, nums);
        // 回溯，回到不加入当前元素的状态
        t.pop_back();
        dfs(cur + 1, nums);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        dfs(0, nums);
        return res;
    }
};
// @lc code=end
