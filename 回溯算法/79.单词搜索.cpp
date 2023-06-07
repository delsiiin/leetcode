/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool dfs(vector<vector<char>> &board, unordered_map<int, bool> &M, string word, int cur, int i, int j)
    {
        if (cur == word.size())
            return true;
        // 越界、被访问过、当前位置的字符不是word对应位置的字符
        if (i >= board.size() || i < 0 ||
            j >= board[0].size() || j < 0 ||
            M.count(i * board.size() + j) || board[i][j] != word[cur])
            return false;

        M[i * board.size() + j] = true;
        if (dfs(board, M, word, cur + 1, i + 1, j) ||
            dfs(board, M, word, cur + 1, i - 1, j) ||
            dfs(board, M, word, cur + 1, i, j + 1) ||
            dfs(board, M, word, cur + 1, i, j - 1))
            return true;
        M[i * board.size() + j] = false;

        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        // 遍历数组找到开头的字符，然后使用回溯算法，哈希表使用一维索引表示二维数组进行记录
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                unordered_map<int, bool> M;
                if (dfs(board, M, word, 0, i, j))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
