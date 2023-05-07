/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string gen_num(string num)
    {
        string res;
        char c = num[0];
        int count = 0;
        for (char x : num)
        {
            if (x != c)
            {
                // 注意：append添加string，push_back添加char，insert添加char
                res.append(to_string(count));
                res.push_back(c);
                count = 1;
                c = x;
            }
            else
            {
                count++;
            }
        }
        res.append(to_string(count));
        res.push_back(c);
        cout << res << ' ';
        return res;
    }

    string countAndSay(int n)
    {
        int i;
        string num = {'1'};
        for (i = 1; i < n; i++)
        {
            num = gen_num(num);
        }
        return num;
    }
};
// @lc code=end
