/*
 * @lc app=leetcode.cn id=576 lang=cpp
 *
 * [576] 出界的路径数
 */

// @lc code=start
class Solution
{
public:
    static constexpr int MOD = 1'000'000'007;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        // 定义上下左右的变化
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int outCounts = 0;
        // dp[总步数][当前横坐标][当前纵坐标]--大小表示从起始点移动i次后到当前位置的路径数
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m, vector<int>(n)));
        dp[0][startRow][startColumn] = 1;
        for (int i = 0; i < maxMove; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    int count = dp[i][j][k];
                    // 遍历到起始位置
                    if (count > 0)
                    {
                        for (auto &direction : directions)
                        {
                            int j1 = j + direction[0], k1 = k + direction[1];
                            if (j1 >= 0 && j1 < m && k1 >= 0 && k1 < n)
                            {
                                // 如果上下左右没出界，则将路径数相加
                                dp[i + 1][j1][k1] = (dp[i + 1][j1][k1] + count) % MOD;
                            }
                            else
                            {
                                // 如果存在出界情况，则将路径数加到outCounts中
                                outCounts = (outCounts + count) % MOD;
                            }
                        }
                    }
                }
            }
        }
        return outCounts;
    }
};

// @lc code=end
