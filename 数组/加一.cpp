/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        /* 转换为整数的方法会溢出 */

        // int integer = 0;
        // int i = digits.size() - 1;
        // for (int num : digits)
        // {
        //     integer += num * pow(10, i);
        //     i--;
        // }
        // integer += 1;
        // vector<int> res;
        // while (integer != 0)
        // {
        //     res.insert(res.begin(), integer % 10);
        //     integer = integer / 10;
        // }
        // return res;

        /* 只需要判断数组最后一位是否为9 */
        int i;
        for (i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] == 9)
            {
                digits[i] = 0;
            }
            else
            {
                digits[i] += 1;
                return digits;
            }
        }
        // 如果数组元素全部为9，则在最前面添加1
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
// @lc code=end
