/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class KthLargest
{
public:
    KthLargest(int k, vector<int> &nums)
    {
        this->K = k;
        for (int num : nums)
        {
            add(num);
        }
    }

    int add(int val)
    {
        Q.push(val);
        if (Q.size() > K)
        {
            Q.pop();
        }
        return Q.top();
    }

private:
    // 使用优先队列解决问题，第一个参数为数据类型，第二个参数为容器及存储类型，第三个参数决定如何排序
    // less--大数优先级高，greater--小数优先级高
    priority_queue<int, vector<int>, greater<int>> Q;
    int K;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
