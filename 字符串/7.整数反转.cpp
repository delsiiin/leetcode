/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include <string>
#include <iostream>
#include <algorithm> //reverse函数需要的库
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        string s = to_string(x);          // 数字（整数、浮点数）转字符串string型
        std::reverse(s.begin(), s.end()); // 内置reverse反转字符串，这里前面加了std::是用于函数名重复区分函数
        int res;
        try
        {
            res = stoi(s); // stoi函数将string转换为int型，溢出会报错；atoi函数将char*转换为int型，溢出不会报错
            if (x < 0)
            {
                res = -res;
            }
        }
        catch (std::exception ex)
        {
            return 0;
        }
        return res;
    }
};
// @lc code=end
