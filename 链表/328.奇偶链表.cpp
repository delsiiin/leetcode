/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head)
            return nullptr;
        if (head && !head->next)
            return head;
        int count = 1;
        ListNode *odd = head;
        ListNode *oddstart = head;
        ListNode *even = head->next;
        ListNode *evenstart = head->next;
        head = head->next->next;
        while (head)
        {
            if (count % 2 == 1)
            {
                odd->next = head;
                odd = head;
                count++;
            }
            else if (count % 2 == 0)
            {
                even->next = head;
                even = head;
                count++;
            }
            head = head->next;
        }
        odd->next = evenstart;
        even->next = nullptr;
        return oddstart;
    }
};
// @lc code=end
