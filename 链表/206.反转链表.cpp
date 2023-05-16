/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.

 */
#include <iostream>
#include <vector>
using namespace std;
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        /* 从左到右依次反转，头指针固定，将头指针的next依次向下指直至nullptr */
        // ListNode *H = head;
        // while (head && head->next)
        // {
        //     ListNode *temp = head->next;
        //     head->next = head->next->next;
        //     temp->next = H;
        //     H = temp;
        // }
        // return H;

        ListNode *rev = nullptr;
        while (head != nullptr)
        {
            ListNode *temp = head->next; // 保存原始head->next
            head->next = rev;            // 将head->next赋值为rev，实现反转
            rev = head;                  // 将rev的值更新为下一个指针
            head = temp;                 // 更新head的值，实现遍历原链表
        }
        return rev;
    }
};
// @lc code=end
