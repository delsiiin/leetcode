/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        vector<vector<int>> M(obstacleGrid.size(), vector<int>(obstacleGrid[0].size()));
        for (int i = 0; i < obstacleGrid.size(); i++)
        {
            M[i][0] = 1;
            if (obstacleGrid[i][0] == 1)
            {
                for (int j = i; j < obstacleGrid.size(); j++)
                {
                    M[j][0] = 0;
                }
                break;
            }
        }
        for (int i = 0; i < obstacleGrid[0].size(); i++)
        {
            M[0][i] = 1;
            if (obstacleGrid[0][i] == 1)
            {
                for (int j = i; j < obstacleGrid[0].size(); j++)
                {
                    M[0][j] = 0;
                }
                break;
            }
        }
        for (int i = 1; i < obstacleGrid.size(); i++)
        {
            for (int j = 1; j < obstacleGrid[0].size(); j++)
            {
                if (obstacleGrid[i][j] != 1)
                    M[i][j] = M[i - 1][j] + M[i][j - 1];
                else
                    M[i][j] = 0;
            }
        }
        return M[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};
// @lc code=end
