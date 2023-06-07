/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // 用滑动窗口解决问题，使用哈希表记录字符有无重复
        unordered_map<char, int> M;
        int index = -1;
        int Max = 0;
        for (int i = 0; i < s.length(); i++)
        {
            // 先判断有无重复字符
            while (index + 1 < s.length() && !M.count(s[index + 1]))
            {
                M[s[index + 1]] = 1;
                index++;
            }
            // 更新最大长度
            Max = max(index - i + 1, Max);
            // 若出现重复字符，则从头开始在哈希表中删除字符
            M.erase(s[i]);
        }
        return Max;
    }
};
// @lc code=end
