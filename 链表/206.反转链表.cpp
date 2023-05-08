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
        // vector<ListNode *> addr;
        // ListNode *temp = head;
        // if (head == nullptr)
        // {
        //     return head;
        // }
        // while (head != nullptr)
        // {
        //     addr.push_back(head);
        //     head = head->next;
        // }
        // ListNode *res = new ListNode(0, addr.back());
        // ListNode *ans = res->next;
        // ListNode *release = res;

        // while (res->next != temp)
        // {
        //     addr.pop_back();
        //     res = res->next;
        //     res->next = addr.back();
        // }
        // res = temp;
        // res->next = nullptr;
        // delete release;
        // return ans;

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
