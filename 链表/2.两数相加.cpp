/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
#include <vector>
using namespace std;

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(0);
        ListNode *res = head;
        int c = 0;
        while (l1 && l2)
        {
            ListNode *N = new ListNode((l1->val + l2->val + c) % 10);
            head->next = N;
            head = N;
            if (l1->val + l2->val + c >= 10)
                c = 1;
            else
                c = 0;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (!l1 && !l2)
        {
            if (c == 1)
            {
                ListNode *N = new ListNode(1);
                head->next = N;
                return res->next;
            }
            else
                return res->next;
        }
        if (l1)
        {
            head->next = l1;
            head = l1;
        }
        else
        {
            head->next = l2;
            head = l2;
        }
        ListNode *H;
        while (head)
        {
            int temp = (head->val + c) % 10;
            if (head->val + c >= 10)
            {
                c = 1;
                head->val = temp;
                H = head;
                head = head->next;
            }
            else
            {
                c = 0;
                head->val = temp;
                break;
            }
        }
        if (c == 1)
        {
            ListNode *N = new ListNode(1);
            H->next = N;
        }
        return res->next;
    }
};
// @lc code=end
