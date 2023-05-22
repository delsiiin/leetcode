/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return nullptr;
        ListNode *dummy = new ListNode(0);
        unordered_map<int, ListNode *> m;
        int count = 0;      // 记录链表长度
        dummy->next = head; // 记录第一个结点的位置
        while (head)
        {
            m[count++] = head;
            head = head->next;
        }
        if (k % count == 0)
            return dummy->next;
        // 变成循环链表
        m[count - 1]->next = dummy->next;
        m[count - 1 - (k % count)]->next = nullptr;
        return m[count - (k % count)];
    }
};
// @lc code=end
