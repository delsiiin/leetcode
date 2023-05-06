/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        // string t;
        // char x;
        // for (char c : s)
        // {
        //     if (c >= 'A' && c <= 'Z')
        //     {
        //         x = c + 32;
        //         t.push_back(x);
        //     }
        //     else if (c >= 'a' && c <= 'z')
        //     {
        //         x = c;
        //         t.push_back(x);
        //     }
        //     else if (c >= '0' && c <= '9')
        //     {
        //         x = c;
        //         t.push_back(x);
        //     }
        // }
        // int i;
        // int len = t.length();
        // for (i = 0; i < len / 2; i++)
        // {
        //     if (t[i] != t[len - 1 - i])
        //     {
        //         return false;
        //     }
        // }
        // return true;

        string sgood;
        for (char ch : s)
        {
            if (isalnum(ch)) // 判断字符是否为数字或字母
            {
                sgood += tolower(ch); // 将字母小写
            }
        }
        string sgood_rev(sgood.rbegin(), sgood.rend()); // rbegin()、rend()用于从后向前遍历，这里生成逆序字符串
        return sgood == sgood_rev;
    }
};

// @lc code=end
