/*
 * @lc app=leetcode.cn id=430 lang=cpp
 *
 * [430] 扁平化多级双向链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (!head)
            return nullptr;
        vector<Node *> m;
        Node *res = head;
        Node *temp;
        while (head)
        {
            if (head->child)
            {
                if (head->next)
                    m.push_back(head->next);
                head->next = head->child;
                head->child = nullptr;
                head->next->prev = head;
                head = head->next;
            }
            else
            {
                temp = head;
                head = head->next;
            }
        }
        while (!m.empty())
        {
            Node *p = m.back();
            m.pop_back();
            temp->next = p;
            p->prev = temp;
            while (p->next)
            {
                p = p->next;
            }
            temp = p;
        }
        return res;
    }
};
// @lc code=end
