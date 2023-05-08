/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <unordered_map>
using namespace std;

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        /* 哈希表判断结点是否被访问过 */
        // ListNode *p = head;
        // unordered_map<ListNode *, int> m;
        // while (p != nullptr && p->next != nullptr)
        // {
        //     m[p] += 1;
        //     if (m[p] > 1)
        //     {
        //         return true;
        //     }
        //     p = p->next;
        // }
        // return false;

        /* Floyd算法（龟兔赛跑算法）-- 快慢指针 */
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (slow != fast) // 如果有环则必能追上
        {
            // 判断fast移动后会不会为空指针
            if (fast == nullptr || fast->next == nullptr)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
// @lc code=end
