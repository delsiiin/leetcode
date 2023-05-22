/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        /* 多源点最短路问题：设置一个超级源点指向所有源点，再通过BFS遍历得到最短路 */
        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size()));
        // visited标记当前位置是否已被访问
        vector<vector<int>> visited(mat.size(), vector<int>(mat[0].size()));
        // 队列存储对应位置的索引i，j
        queue<pair<int, int>> Q;
        // 先将所有的0入队（初始状态默认超级源点直接出队）
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 0)
                {
                    visited[i][j] = 1;
                    Q.push({i, j});
                }
            }
        }
        while (!Q.empty())
        {
            auto [i, j] = Q.front();
            Q.pop();
            // 遍历上下左右四个位置，判断是否被访问过，将未访问过的位置入队，该位置对应的路径长度加一
            if (i + 1 < mat.size() && !visited[i + 1][j])
            {
                Q.push({i + 1, j});
                visited[i + 1][j] = 1;
                res[i + 1][j] = res[i][j] + 1;
            }
            if (j + 1 < mat[0].size() && !visited[i][j + 1])
            {
                Q.push({i, j + 1});
                visited[i][j + 1] = 1;
                res[i][j + 1] = res[i][j] + 1;
            }
            if (i - 1 >= 0 && !visited[i - 1][j])
            {
                Q.push({i - 1, j});
                visited[i - 1][j] = 1;
                res[i - 1][j] = res[i][j] + 1;
            }
            if (j - 1 >= 0 && !visited[i][j - 1])
            {
                Q.push({i, j - 1});
                visited[i][j - 1] = 1;
                res[i][j - 1] = res[i][j] + 1;
            }
        }
        return res;
    }
};
// @lc code=end
