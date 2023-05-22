/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        // 建立哈希表存储复制与被复制链表同一位置的地址
        unordered_map<Node *, Node *> m;
        Node *root = new Node(0);
        Node *res = root;
        while (head)
        {
            Node *node = new Node(head->val);
            m[head] = node;
            root->next = node;
            root = node;
            head = head->next;
        }
        for (auto x : m)
        {
            // 根据哈希表对新链表的random指针进行赋值
            if (x.first->random)
                x.second->random = m[x.first->random];
            else
                x.second->random = nullptr;
        }
        return res->next;
    }
};
// @lc code=end
