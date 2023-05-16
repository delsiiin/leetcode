/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        // 动态规划解决问题，关键是在得出状态转换方程
        // 判断第i到j的字符串是否为回文串，则需判断第i+1到j-1的字符串是否为回文串且s[i]是否等于s[j]

        if (s.length() == 1) // 如果只有一个字符，则直接返回
            return s;
        // 创建一个二维数组记录从i到j的字符串是否为回文串
        vector<vector<int>> dp(s.length(), vector<int>(s.length()));
        int index = 0;   // 记录最长回文串的起始索引
        int max_len = 1; // 记录最长回文串的长度，默认为1
        // 初始化以单个字符成串的回文串
        for (int i = 0; i < s.length(); i++)
        {
            dp[i][i] = 1;
        }
        // 从字符串长度为2开始循环
        for (int L = 2; L <= s.length(); L++)
        {
            // 从第一个字符开始循环，到总长度减去字符串长度为止
            for (int i = 0; i <= s.length() - L; i++)
            {
                // 通过L和i得到j的大小
                int j = L + i - 1;
                // 若s[i] != s[j]，则记录为0
                if (s[i] != s[j])
                    dp[i][j] = 0;
                // 若s[i] == s[j]并且字符串长度不超过3，则直接记录为1
                else if (j - i < 3 && s[i] == s[j])
                    dp[i][j] = 1;
                // 其余s[i] == s[j]的情况则判断第i+1到j-1的字符串是否为回文串
                else if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                // 第i到j的字符串如果为回文串，则将其长度与最大长度进行比较后迭代，并记录起始地址
                if (dp[i][j] && L > max_len)
                {
                    index = i;
                    max_len = L;
                }
            }
        }
        string res;
        // 返回从index开始，长度为max_len的回文子串
        res = s.substr(index, max_len);
        return res;
    }
};
// @lc code=end
