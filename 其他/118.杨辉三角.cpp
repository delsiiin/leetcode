/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> triangle(numRows);
        triangle[0] = {1};
        if (numRows == 1)
            return triangle;
        triangle[1] = {1, 1};
        if (numRows == 2)
            return triangle;
        for (int i = 2; i < numRows; i++)
        {
            triangle[i].push_back(1);
            for (int j = 0; j < i - 1; j++)
            {
                int sum = triangle[i - 1][j] + triangle[i - 1][j + 1];
                triangle[i].push_back(sum);
            }
            triangle[i].push_back(1);
        }
        return triangle;
    }
};
// @lc code=end
