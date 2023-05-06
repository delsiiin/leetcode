/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int res;
        int i, j;
        string sub;
        for (char c : s)
        {
            // 出现多少次的问题可考虑哈希表
            // 寻找最后一次出现和第一次出现的位置，判断是否相同
            i = s.find_first_of(c);
            j = s.find_last_of(c);
            if (i == j)
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end
