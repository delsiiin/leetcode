/*
 * @lc app=leetcode.cn id=1575 lang=cpp
 *
 * [1575] 统计所有可行路径
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    static constexpr int mod = 1000000007;
    // f[location][fuel]--代表从location出发，剩余油量为fuel时，到达目标地点的路径数目
    vector<vector<int>> f;

public:
    // 定义dfs递归的base case：
    // 有效情况--如果当前位置i就是目的地finish的话，就算做一次有效路径，对路径数加1
    // 无效情况--(1)当油量耗完，所在位置不在finish(2)油量不为0，但无法再移动到任何位置
    int dfs(const vector<int> &locations, int pos, int finish, int rest)
    {
        // 若f[pos][rest]已经被定义，则直接返回
        if (f[pos][rest] != -1)
        {
            return f[pos][rest];
        }

        // 初始化f[pos][rest]
        f[pos][rest] = 0;
        // 如果当前位置到finish的油量大于剩余油量，则返回0（两点之间线段最短，直接从pos到finish的距离一定耗油最少）
        if (abs(locations[pos] - locations[finish]) > rest)
        {
            return 0;
        }

        // 遍历从pos到其余任何一个地点，加上能够到达的其余地点到达finish的路径数
        int n = locations.size();
        for (int i = 0; i < n; ++i)
        {
            if (pos != i)
            {
                if (int cost = abs(locations[pos] - locations[i]); cost <= rest)
                {
                    f[pos][rest] += dfs(locations, i, finish, rest - cost);
                    f[pos][rest] %= mod;
                }
            }
        }
        // 如果当前pos已经在finish位置，则路径数加一
        if (pos == finish)
        {
            f[pos][rest] += 1;
            f[pos][rest] %= mod;
        }
        return f[pos][rest];
    }

    int countRoutes(vector<int> &locations, int start, int finish, int fuel)
    {
        // 初始化f的fuel为-1
        f.assign(locations.size(), vector<int>(fuel + 1, -1));
        return dfs(locations, start, finish, fuel);
    }
};

// @lc code=end
