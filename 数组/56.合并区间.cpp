/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // 先对输入的二维数组进行排序，将二元组按左元素大小从小到大排列
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int i = 0;
        // 将第一个二元组先入列
        res.push_back(intervals[0]);
        for (vector<int> mem : intervals)
        {
            // 比较当前遍历的二元组的左元素与最新入列的二元组的右元素
            if (mem.front() > res[i].back())
            {
                // 如果大于，则将当前遍历的二元组入列作为新一轮的比较对象
                res.push_back(mem);
                i++;
            }
            else
            {
                // 如果小于，则将最新入列的二元组的右元素替换为当前遍历二元组的左元素
                res[i][1] = max(res[i].back(), mem.back());
            }
        }
        return res;
    }
};
// @lc code=end
