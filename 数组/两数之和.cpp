/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        /* 暴力破解，效率低 */

        // int i, j;
        // vector<int> res;
        // for (int i = 0; i < nums.size() - 1; i++)
        // {
        //     for (int j = i + 1; j < nums.size(); j++)
        //     {
        //         if (nums[i] + nums[j] == target)
        //         {
        //             res.push_back(i);
        //             res.push_back(j);
        //             return res;
        //         }
        //     }
        // }
        // return res;

        /* 哈希表，效率高 */
        unordered_map<int, int> m;
        int i;
        for (i = 0; i < nums.size(); i++)
        {
            auto it = m.find(target - nums[i]); // find函数返回对应key的迭代器
            if (it != m.end())                  // 注意find函数找不到返回end()而不是null
            {
                return {it->second, i};
            }
            m[nums[i]] = i; // 不能放在前面，因为会导致输出重复的位置
        }
        return {};
    }
};
// @lc code=end
