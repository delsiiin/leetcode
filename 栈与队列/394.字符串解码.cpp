/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        stack<string> Stack;
        string k;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                k.push_back(s[i]);
            }
            else if (s[i] != ']')
            {
                if (!k.empty())
                {
                    Stack.push(k);
                    k.clear();
                }
                string temp;
                temp.push_back(s[i]);
                Stack.push(temp);
            }
            else if (s[i] == ']')
            {
                vector<string> sub;
                while (Stack.top() != "[")
                {
                    sub.push_back(Stack.top());
                    Stack.pop();
                }
                Stack.pop();
                reverse(sub.begin(), sub.end());
                int round = stoi(Stack.top());
                Stack.pop();
                string Sub;
                for (string s : sub)
                {
                    Sub += s;
                }
                string res;
                for (int i = 0; i < round; i++)
                {
                    res += Sub;
                }
                Stack.push(res);
            }
        }
        vector<string> ans;
        while (!Stack.empty())
        {
            ans.push_back(Stack.top());
            Stack.pop();
        }
        reverse(ans.begin(), ans.end());
        string result;
        for (string s : ans)
        {
            result += s;
        }
        return result;
    }
};
// @lc code=end
