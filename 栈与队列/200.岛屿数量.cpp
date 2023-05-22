/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        // 广度优先遍历
        int res = 0;
        queue<vector<int>> Q;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                // 遍历二维数组中的每个结点
                if (grid[i][j] == '1')
                {
                    // 每进行一次广度遍历，则岛屿数+1
                    res += 1;
                    // 将遍历中为'1'的元素修改为'0'，防止再次遍历
                    grid[i][j] = '0';
                    Q.push({i, j});
                    while (!Q.empty())
                    {
                        auto index = Q.front();
                        Q.pop();
                        // 对上下左右的元素进行判断并放入队列中
                        if (index.front() - 1 >= 0 && grid[index.front() - 1][index.back()] == '1')
                        {
                            Q.push({index.front() - 1, index.back()});
                            grid[index.front() - 1][index.back()] = '0';
                        }
                        if (index.front() + 1 < grid.size() && grid[index.front() + 1][index.back()] == '1')
                        {
                            Q.push({index.front() + 1, index.back()});
                            grid[index.front() + 1][index.back()] = '0';
                        }
                        if (index.back() - 1 >= 0 && grid[index.front()][index.back() - 1] == '1')
                        {
                            Q.push({index.front(), index.back() - 1});
                            grid[index.front()][index.back() - 1] = '0';
                        }
                        if (index.back() + 1 < grid[0].size() && grid[index.front()][index.back() + 1] == '1')
                        {
                            Q.push({index.front(), index.back() + 1});
                            grid[index.front()][index.back() + 1] = '0';
                        }
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
