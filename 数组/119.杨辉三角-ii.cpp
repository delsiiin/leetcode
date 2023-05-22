/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> res;
        res.push_back({1});
        if (rowIndex >= 1)
            res.push_back({1, 1});
        for (int i = 2; i <= rowIndex; i++)
        {
            vector<int> tri;
            tri.push_back(1);
            for (int j = 0; j < i - 1; j++)
            {
                tri.push_back(res[i - 1][j] + res[i - 1][j + 1]);
            }
            tri.push_back(1);
            res.push_back(tri);
        }
        return res[rowIndex];
    }
};
// @lc code=end
