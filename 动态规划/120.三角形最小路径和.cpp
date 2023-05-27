/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<vector<int>> Min(triangle);
        for (int i = 0; i < triangle.size(); i++)
        {
            if (i != 0)
            {
                int len = triangle[i].size();
                Min[i][0] = Min[i - 1].front() + triangle[i][0];
                for (int j = 1; j < len - 1; j++)
                {
                    Min[i][j] = min(Min[i - 1][j - 1], Min[i - 1][j]) + triangle[i][j];
                }
                Min[i][len - 1] = Min[i - 1].back() + triangle[i][len - 1];
            }
            else
                Min[i][0] = triangle[i][0];
        }
        sort(Min[triangle.size() - 1].begin(), Min[triangle.size() - 1].end());
        return Min[triangle.size() - 1][0];
    }
};
// @lc code=end
