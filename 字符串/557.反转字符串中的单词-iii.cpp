/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        /* 使用栈解决问题 */
        string res;
        stack<char> S;
        s.push_back(' ');
        for (char c : s)
        {
            if (c != ' ')
                S.push(c);
            else
            {
                while (!S.empty())
                {
                    res.push_back(S.top());
                    S.pop();
                }
                res.push_back(' ');
            }
        }
        s.pop_back();
        res.pop_back();
        return res;
    }
};
// @lc code=end
