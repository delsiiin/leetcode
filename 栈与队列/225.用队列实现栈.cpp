/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
public:
    MyStack()
    {
    }

    void push(int x)
    {
        Q1.push(x);
    }

    int pop()
    {
        while (Q1.size() > 1)
        {
            Q2.push(Q1.front());
            Q1.pop();
        }
        int res = Q1.front();
        Q1.pop();
        while (!Q2.empty())
        {
            Q1.push(Q2.front());
            Q2.pop();
        }
        return res;
    }

    int top()
    {
        return Q1.back();
    }

    bool empty()
    {
        if (Q1.empty())
            return true;
        return false;
    }

private:
    queue<int> Q1;
    queue<int> Q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
