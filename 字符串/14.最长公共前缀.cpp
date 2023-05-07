/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        // 纵向扫描
        string min;
        string sub;
        int i;
        min = strs[0];
        sub.push_back(min[0]);
        for (i = 0; i < min.length(); i++)
        {
            for (string s : strs)
            {
                if (s.find(sub) != 0 && i == 0)
                {
                    return "";
                }
                else if (s.find(sub) != 0)
                {
                    sub.pop_back();
                    return sub;
                }
            }
            if (i + 1 == min.length())
            {
                return sub;
            }
            sub.push_back(min[i + 1]);
        }
        return "";
    }
};
// @lc code=end
