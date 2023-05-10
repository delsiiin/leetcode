/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        vector<int> m;
        uint32_t sum = 0;
        while (n)
        {
            m.push_back(n % 2);
            n = n / 2;
        }
        while (m.size() != 32)
        {
            m.push_back(0);
        }
        int i = 0;
        for (int num : m)
        {
            if (num)
                sum += pow(2, 31 - i);
            i++;
        }
        return sum;
    }
};
// @lc code=end
