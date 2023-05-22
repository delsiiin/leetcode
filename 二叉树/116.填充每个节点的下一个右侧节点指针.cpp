/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
#include <iostream>
#include <queue>
using namespace std;

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return nullptr;
        queue<Node *> Q;
        Node *res = root;
        Q.push(root);
        // 层序遍历+修改next指针
        while (!Q.empty())
        {
            int sz = Q.size();
            Node *temp;
            while (sz)
            {
                temp = Q.front();
                Q.pop();
                if (sz > 1)
                    temp->next = Q.front();
                if (temp->left)
                    Q.push(temp->left);
                if (temp->right)
                    Q.push(temp->right);
                sz--;
            }
        }
        return res;
    }
};
// @lc code=end
