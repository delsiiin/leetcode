/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> RPN;
        for (string s : tokens)
        {
            if (s != "+" && s != "-" && s != "*" && s != "/")
                RPN.push(stoi(s));
            if (s == "+")
            {
                int b = RPN.top();
                RPN.pop();
                int a = RPN.top();
                RPN.pop();
                RPN.push(a + b);
            }
            if (s == "-")
            {
                int b = RPN.top();
                RPN.pop();
                int a = RPN.top();
                RPN.pop();
                RPN.push(a - b);
            }
            if (s == "*")
            {
                int b = RPN.top();
                RPN.pop();
                int a = RPN.top();
                RPN.pop();
                RPN.push(a * b);
            }
            if (s == "/")
            {
                int b = RPN.top();
                RPN.pop();
                int a = RPN.top();
                RPN.pop();
                RPN.push(a / b);
            }
        }
        return RPN.top();
    }
};
// @lc code=end
