/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // 哈希表解决
        // unordered_map<char, int> m;
        // for (char c : s)
        // {
        //     if (t.find(c) != -1)
        //     {
        //         m[c] += 1;
        //     }
        //     else
        //     {
        //         return false;
        //     }
        // }
        // for (char c : t)
        // {
        //     if (s.find(c) != -1)
        //     {
        //         m[c] -= 1;
        //     }
        //     else
        //     {
        //         return false;
        //     }
        // }
        // for (auto unit : m)
        // {
        //     if (unit.second != 0)
        //     {
        //         return false;
        //     }
        // }
        // return true;

        // 排序解决
        sort(s.begin(), s.end()); // 按ascii码从小到大排序
        sort(t.begin(), t.end());
        return s == t;
    }
};
// @lc code=end
