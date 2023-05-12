/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        unordered_map<int, int> index_r;
        unordered_map<int, int> index_c;
        int len_r = matrix.size();
        int len_c = matrix[0].size();
        for (int i = 0; i < len_r; i++)
        {
            for (int j = 0; j < len_c; j++)
            {
                if (matrix[i][j] == 0)
                {
                    index_r[i] = 0;
                    index_c[j] = 0;
                }
            }
        }
        for (int i = 0; i < len_r; i++)
        {
            if (index_r.count(i))
            {
                for (int j = 0; j < len_c; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 0; j < len_c; j++)
        {
            if (index_c.count(j))
            {
                for (int i = 0; i < len_r; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
// @lc code=end
