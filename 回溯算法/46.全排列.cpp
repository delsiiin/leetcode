/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    // unordered_set<string> M;
    // void helper(vector<int> &temp, string &S, vector<int> nums)
    // {
    //     int size = nums.size();
    //     for (int i = 0; i < size; i++)
    //     {
    //         int index = random() % nums.size();
    //         temp.push_back(nums[index]);
    //         S.append(to_string(nums[index]));
    //         nums.erase(nums.begin() + index);
    //     }
    // }
    // vector<vector<int>> permute(vector<int> &nums)
    // {
    //     int range = 1;
    //     int count = 0;
    //     vector<vector<int>> res;
    //     for (int i = 1; i <= nums.size(); i++)
    //     {
    //         range *= i;
    //     }
    //     while (count != range)
    //     {
    //         vector<int> temp;
    //         string S;
    //         helper(temp, S, nums);
    //         if (!M.count(S))
    //         {
    //             M.insert(S);
    //             res.push_back(temp);
    //             count++;
    //         }
    //     }
    //     return res;
    // }

    // 回溯算法
    void backtrack(vector<vector<int>> &res, vector<int> &output, int first, int len)
    {
        // 所有数都填完了
        if (first == len)
        {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; ++i)
        {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }
};
// @lc code=end
