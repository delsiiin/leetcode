/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int len_r = matrix.size();
        int len_c = matrix[0].size();
        vector<vector<int>> Min(matrix);
        for (int i = 0; i < len_r; i++)
        {
            for (int j = 0; j < len_c; j++)
            {
                if (i == 0)
                    Min[i][j] = matrix[i][j];
                else
                {
                    if (j == 0)
                    {
                        Min[i][j] = matrix[i][j] + min(Min[i - 1][j], Min[i - 1][j + 1]);
                    }
                    else if (j == len_c - 1)
                    {
                        Min[i][j] = matrix[i][j] + min(Min[i - 1][j], Min[i - 1][j - 1]);
                    }
                    else
                    {
                        set<int> temp;
                        temp.insert(Min[i - 1][j]);
                        temp.insert(Min[i - 1][j - 1]);
                        temp.insert(Min[i - 1][j + 1]);
                        Min[i][j] = matrix[i][j] + *(temp.begin());
                    }
                }
            }
        }
        sort(Min[len_r - 1].begin(), Min[len_r - 1].end());
        return Min[len_r - 1][0];
    }
};
// @lc code=end
