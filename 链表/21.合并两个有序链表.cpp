/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // ListNode *p = new ListNode();
        // vector<int> m;
        // if (list1 == nullptr && list2 == nullptr)
        //     return nullptr;
        // while (list1 != nullptr && list1->next != nullptr)
        // {
        //     m.push_back(list1->val);
        //     list1 = list1->next;
        // }
        // if (list1 != nullptr)
        //     m.push_back(list1->val);
        // while (list2 != nullptr && list2->next != nullptr)
        // {
        //     m.push_back(list2->val);
        //     list2 = list2->next;
        // }
        // if (list2 != nullptr)
        //     m.push_back(list2->val);
        // sort(m.rbegin(), m.rend());
        // for (int val : m)
        // {
        //     ListNode *res = new ListNode(); // 作用域只在for循环内，for循环外res不存在
        //     p->val = val;
        //     res->next = p;
        //     p = res;
        // }
        // ListNode *ans = p->next;
        // return ans;

        ListNode *res = new ListNode(-1); // 新添加一个头指针
        ListNode *temp = res;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
            } // 连接二者中较小的节点，list1或list2随即向后移一个节点
            else
            {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        // 直接拼接较长链表的后续部分
        if (list1 == nullptr)
        {
            temp->next = list2;
        }
        else
        {
            temp->next = list1;
        }
        return res->next;
    }
};
// @lc code=end
