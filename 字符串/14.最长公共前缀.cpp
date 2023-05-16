/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string min = strs[0];
        string res = "";
        for (int i = 0; i < min.length(); i++)
        {
            res.push_back(min[i]);
            for (string s : strs)
            {
                if (s.find(res) != 0)
                {
                    res.pop_back();
                    return res;
                }
            }
        }
        return res;
    }
};
// @lc code=end
