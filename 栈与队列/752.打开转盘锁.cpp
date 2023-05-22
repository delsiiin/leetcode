/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<string> move(string str)
    {
        vector<string> res;
        string temp = str;
        for (int i = 0; i < str.length(); i++)
        {
            str = temp;
            if (str[i] == '9')
            {
                str[i] = '0';
                res.push_back(str);
            }
            else
            {
                str[i] = str[i] + 1;
                res.push_back(str);
            }
            str = temp;
            if (str[i] == '0')
            {
                str[i] = '9';
                res.push_back(str);
            }
            else
            {
                str[i] = str[i] - 1;
                res.push_back(str);
            }
        }
        return res;
    }

    int openLock(vector<string> &deadends, string target)
    {
        if (target == "0000")
            return 0;
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000"))
            return -1;
        queue<string> Q;
        unordered_map<string, int> M;
        M["0000"] = 0;
        Q.push("0000");
        while (!Q.empty())
        {
            string temp = Q.front();
            int step = M[temp];
            Q.pop();
            vector<string> res = move(temp);
            for (string s : res)
            {
                cout << s;
                if (dead.count(s))
                    continue;
                if (s == target)
                    return step + 1;
                if (!M.count(s))
                {
                    M[s] = step + 1;
                    Q.push(s);
                }
            }
        }
        return -1;
    }
};
// @lc code=end
