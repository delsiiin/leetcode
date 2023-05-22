/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
public:
    MyQueue()
    {
    }

    void push(int x)
    {
        S1.push(x);
        // 当输出栈为空时，将输入栈的内容转移到输出栈中，即能改变输出顺序
        if (S2.empty())
        {
            while (!S1.empty())
            {
                S2.push(S1.top());
                S1.pop();
            }
        }
    }

    int pop()
    {
        int res = S2.top();
        S2.pop();
        // 当输出栈为空时，将输入栈的内容转移到输出栈中，即能改变输出顺序
        if (S2.empty())
        {
            while (!S1.empty())
            {
                S2.push(S1.top());
                S1.pop();
            }
        }
        return res;
    }

    int peek()
    {
        return S2.top();
    }

    bool empty()
    {
        if (S1.empty() && S2.empty())
            return true;
        return false;
    }

private:
    stack<int> S1; // 输入栈
    stack<int> S2; // 输出栈
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
