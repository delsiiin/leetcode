/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<string> temp(strs);
        unordered_map<string, vector<string>> M;
        vector<vector<string>> res;
        for (int i = 0; i < strs.size(); i++)
        {
            // 使用对字符串排序，如果使用相同的字母得到的结果是相同的
            sort(temp[i].begin(), temp[i].end());
            M[temp[i]].push_back(strs[i]);
        }
        for (auto mem : M)
        {
            res.push_back(mem.second);
        }
        return res;
    }
};
// @lc code=end
