/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> Stack;
        for (char c : s)
        {
            if (c != ')' && c != ']' && c != '}')
                Stack.push(c);
            else if (c == ')')
            {
                if (Stack.empty() || Stack.top() != '(')
                    return false;
                Stack.pop();
            }
            else if (c == ']')
            {
                if (Stack.empty() || Stack.top() != '[')
                    return false;
                Stack.pop();
            }
            else if (c == '}')
            {
                if (Stack.empty() || Stack.top() != '{')
                    return false;
                Stack.pop();
            }
        }
        if (Stack.empty())
            return true;
        return false;
    }
};
// @lc code=end
