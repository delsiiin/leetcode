/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        vector<vector<int>> Min(grid.size(), vector<int>(grid[0].size()));
        for (int i = 0; i < grid.size(); i++)
        {
            if (i == 0)
                Min[i][0] = grid[0][0];
            else
                Min[i][0] = Min[i - 1][0] + grid[i][0];
        }
        for (int i = 0; i < grid[0].size(); i++)
        {
            if (i == 0)
                Min[0][i] = grid[0][0];
            else
                Min[0][i] = Min[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < grid.size(); i++)
        {
            for (int j = 1; j < grid[0].size(); j++)
            {
                Min[i][j] = grid[i][j] + min(Min[i - 1][j], Min[i][j - 1]);
            }
        }
        return Min[grid.size() - 1][grid[0].size() - 1];
    }
};
// @lc code=end
