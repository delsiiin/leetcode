/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // 用一个哈希表存储改变后的位置
        unordered_map<int, vector<int>> m;
        int i, j, k = 0; // k 作为每个元素的标识符，防止有重复的元素出现
        int n = matrix.size();
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                m[k].push_back(j);
                m[k].push_back(n - 1 - i);
                m[k].push_back(matrix[i][j]);
                k += 1;
            }
        }
        for (auto temp : m) // 使用for循环遍历map容器，temp为迭代器（元组）
        {
            matrix[temp.second[0]][temp.second[1]] = temp.second[2];
        }
    }
};
// @lc code=end
