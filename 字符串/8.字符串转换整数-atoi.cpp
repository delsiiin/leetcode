/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        string num;
        string res;
        int N = 0;
        int plus = -1;
        for (char c : s)
        {
            if (c != ' ')
            {
                if (c == '+')
                {
                    plus = 1;
                    num = s.substr(s.find(c) + 1);
                }
                else if (c == '-')
                {
                    plus = 0;
                    num = s.substr(s.find(c) + 1);
                }
                else
                {
                    plus = 1;
                    num = s.substr(s.find(c));
                }
                break;
            }
        }
        for (char c : num)
        {
            if (c < '0' || c > '9')
            {
                break;
            }
            res.push_back(c);
        }
        if (res.empty())
        {
            return 0;
        }
        else
        {
            try
            {
                N = stoi(res);
            }
            catch (std::exception e)
            {
                if (plus == 1)
                {
                    return pow(2, 31) - 1;
                }
                else if (plus == 0)
                {
                    return -pow(2, 31);
                }
            }
            if (plus == 1)
            {
                return N;
            }
            else if (plus == 0)
            {
                return -N;
            }
        }
        return 0;
    }
};
// @lc code=end
