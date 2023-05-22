/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> index;
        vector<int> res(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!index.empty())
            {
                if (temperatures[i] > temperatures[index.top()])
                {
                    res[index.top()] = i - index.top();
                    index.pop();
                }
                else
                    break;
            }
            if (i < temperatures.size() - 1 && temperatures[i] >= temperatures[i + 1])
                index.push(i);
            else if (i < temperatures.size() - 1 && temperatures[i] < temperatures[i + 1])
                res[i] = 1;
        }
        return res;
    }
};
// @lc code=end
