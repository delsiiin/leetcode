/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
#include <stack>
#include <math.h>
using namespace std;

class MinStack
{
public:
    MinStack()
    {
        this->Stack = {};
        this->min_stack = {};
    }

    void push(int val)
    {
        if (Stack.empty())
        {
            Stack.push(val);
            min_stack.push(val);
        }
        else
        {
            Stack.push(val);
            if (val <= min_stack.top()) // 仅当待push值小于等于最小栈栈顶时，置入最小栈
                min_stack.push(val);
        }
    }

    void pop()
    {
        if (Stack.top() == min_stack.top()) // 仅当待top值等于最小栈栈顶时，出最小栈
            min_stack.pop();
        Stack.pop();
    }

    int top()
    {
        return Stack.top();
    }

    int getMin()
    {
        return min_stack.top();
    }

private:
    stack<int> Stack;
    stack<int> min_stack; // 辅助栈，记录最小值
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
