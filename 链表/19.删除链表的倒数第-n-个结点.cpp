/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int count = 0;
        // 创建dummy指针指向头指针，便于进行删除操作（高频）
        ListNode *dummy = new ListNode(0, head);
        ListNode *temp = dummy;
        ListNode *ans = dummy; // dummy、temp、ans、release对val和next的操作会互相影响，因为均是对new的地址进行操作
        ListNode *release = dummy;
        while (temp->next != nullptr) // 空指针使用nullptr
        {
            temp = temp->next;
            count++;
        }

        int i = 1;
        while (i != count - n + 1)
        {
            dummy = dummy->next;
            i++;
        }
        dummy->next = dummy->next->next;
        ans = ans->next; // 这里不能直接返回head，因为如果删除的为头指针，则需要重新为head赋值（即head的下一个节点）
        delete release;  // 这里不能直接delete dummy，因为此时dummy相较于初始化时已经改变了，所以使用一个临时变量对初始化的指针值释放对应空间
        return ans;
    }
};

// @lc code=end
