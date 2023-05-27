/*
 * @lc app=leetcode.cn id=1289 lang=cpp
 *
 * [1289] 下降路径最小和  II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    vector<int> get_min(vector<int> Min)
    {
        sort(Min.begin(), Min.end());
        return {Min.front(), Min[1]};
    }

    int minFallingPathSum(vector<vector<int>> &grid)
    {
        vector<vector<int>> Min = grid;
        for (int i = 1; i < grid.size(); i++)
        {
            vector<int> temp = get_min(Min[i - 1]);
            for (int j = 0; j < grid[0].size(); j++)
            {
                // 只需判断列坐标是否相同，分别加上一行得到的次小值和最小值
                if (Min[i - 1][j] == temp.front())
                    Min[i][j] += temp.back();
                else
                    Min[i][j] += temp.front();
            }
        }
        sort(Min[grid.size() - 1].begin(), Min[grid.size() - 1].end());
        return Min[grid.size() - 1].front();
    }
};
// @lc code=end
