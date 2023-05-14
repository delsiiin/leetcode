/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        /* 哈希表存储访问次数 */
        // unordered_map<ListNode *, int> m;
        // while (headA)
        // {
        //     m[headA] += 1;
        //     headA = headA->next;
        // }
        // while (headB)
        // {
        //     m[headB] += 1;
        //     if (m[headB] == 2)
        //         return headB;
        //     headB = headB->next;
        // }
        // return nullptr;

        /* 双指针法--时间复杂度O(m+n)、空间复杂度O(1) */
        ListNode *a = headA;
        ListNode *b = headB;
        // 假设公共部分长度为x,a的剩余部分长度为m，b的剩余部分长度为n
        // 当某一条链表先遍历完成时，再进行另一条链表的遍历
        // 这样当两个指针都指向第一个重合的位置时，均走了x+m+n步
        while (a != b)
        {
            if (a)
            {
                a = a->next;
            }
            else
            {
                a = headB;
            }
            if (b)
            {
                b = b->next;
            }
            else
            {
                b = headA;
            }
        }
        return a;
    }
};
// @lc code=end
