/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode *head)
    {
        ListNode *p = head;
        vector<int> m;
        while (p != nullptr)
        {
            m.push_back(p->val);
            p = p->next;
        }
        int left = 0, right = m.size() - 1;
        while (left != right && left - right != 1)
        {
            if (m[left] != m[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
// @lc code=end
