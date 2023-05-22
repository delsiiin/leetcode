/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        unordered_map<int, int> M; // 记录房号和是否被访问过
        queue<int> Q;
        M[0] = 1;
        for (int x : rooms[0])
        {
            Q.push(x);
            M[x] = 1;
        }
        while (!Q.empty())
        {
            int roomindex = Q.front();
            Q.pop();
            for (int x : rooms[roomindex]) // 对每个房间中的钥匙，若未访问过对应房间，则入队且标记为已访问
            {
                if (!M.count(x))
                {
                    Q.push(x);
                    M[x] = 1;
                }
            }
        }
        if (M.size() == rooms.size()) // 比较标记的不同房间数是否与总房间数相等
            return true;
        return false;
    }
};
// @lc code=end
