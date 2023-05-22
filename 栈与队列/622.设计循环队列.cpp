/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue
{
public:
    MyCircularQueue(int k)
    {
        vector<int> temp(k + 1);
        Queue = temp;
        this->head = 0;
        this->tail = 0;
        this->size = k + 1;
    }

    bool enQueue(int value)
    {
        if (isFull())
        {
            return false;
        }
        Queue[tail] = value;
        tail = (tail + 1) % size;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        head = (head + 1) % size;
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return Queue[head];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        // c++中%运算，当被模数为负数时，模数为正数时，结果为负数
        // 尽量转换为正数模正数
        return Queue[(tail - 1 + size) % size];
    }

    bool isEmpty()
    {
        if (head == tail)
            return true;
        return false;
    }

    bool isFull()
    {
        if ((tail - head + 1) % size == 0)
            return true;
        else
        {
            return false;
        }
    }

private:
    vector<int> Queue;
    int size;
    int head;
    int tail;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end
