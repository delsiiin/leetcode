/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    unordered_map<string, bool> M;
    string helper(int left, int right)
    {
        string gen;
        gen.append("(");
        left--;
        while (left || right)
        {
            int flag = random() % 2;
            if (left <= right && flag == 0 && left)
            {
                gen.append("(");
                left--;
            }
            else if (left < right && flag == 1)
            {
                gen.append(")");
                right--;
            }
        }
        return gen;
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        int i = 60000;
        while (i)
        {
            string gen = helper(n, n);
            if (!M.count(gen))
            {
                M[gen] = true;
                res.push_back(gen);
            }
            i--;
        }
        return res;
    }
};
// @lc code=end
