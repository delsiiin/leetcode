/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stdlib.h>
using namespace std;

class Solution
{
public:
    unordered_map<char, vector<char>> M;
    unordered_map<string, bool> judge;
    void gen_map(unordered_map<char, vector<char>> &M)
    {
        M['2'] = {'a', 'b', 'c'};
        M['3'] = {'d', 'e', 'f'};
        M['4'] = {'g', 'h', 'i'};
        M['5'] = {'j', 'k', 'l'};
        M['6'] = {'m', 'n', 'o'};
        M['7'] = {'p', 'q', 'r', 's'};
        M['8'] = {'t', 'u', 'v'};
        M['9'] = {'w', 'x', 'y', 'z'};
    }

    string helper(string digits)
    {
        string temp;
        for (int i = 0; i < digits.length(); i++)
        {
            int index = random() % M[digits[i]].size();
            temp.push_back(M[digits[i]][index]);
        }
        return temp;
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
            return {};
        gen_map(M);
        int range = 1;
        int count = 0;
        for (char digit : digits)
        {
            range *= M[digit].size();
        }
        vector<string> res(range);
        while (count != range)
        {
            string temp = helper(digits);
            if (!judge.count(temp))
            {
                judge[temp] = true;
                res[count++] = temp;
            }
        }
        return res;
    }
};
// @lc code=end
