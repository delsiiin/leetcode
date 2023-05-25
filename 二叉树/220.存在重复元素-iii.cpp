/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff)
    {
        /* 滑动窗口+有序集合set */
        set<int> S;
        for (int i = 0; i < nums.size(); i++)
        {
            // lower_bound--返回第一个大于等于参数的元素的迭代器
            auto iter = S.lower_bound((long long)(nums[i] - valueDiff));
            if (iter != S.end() && *iter <= (long long)(nums[i] + valueDiff))
                return true;
            // insert(对应值)
            S.insert(nums[i]);
            if (i >= indexDiff)
                // erase(对应值)
                S.erase(nums[i - indexDiff]);
        }
        return false;
    }
};
// @lc code=end
