/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // 使用三个数组作为索引表判断不同行、列、小九宫格是否存在重复数字
        int row[9][9];
        int col[9][9];
        int subbox[3][3][9];

        int i, j;
        int index;
        // memset函数需要头文件<string.h>
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(subbox, 0, sizeof(subbox));
        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    // 将字符转换为整数-- 减去'0'
                    index = board[i][j] - '0' - 1; // 索引范围为0-8
                    row[i][index]++;
                    col[j][index]++;
                    subbox[i / 3][j / 3][index]++;

                    if (row[i][index] > 1 || col[j][index] > 1 || subbox[i / 3][j / 3][index] > 1)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end
