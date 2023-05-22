/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start

// Definition for a Node.
// class Node
// {
// public:
//     int val;
//     vector<Node *> neighbors;
//     Node()
//     {
//         val = 0;
//         neighbors = vector<Node *>();
//     }
//     Node(int _val)
//     {
//         val = _val;
//         neighbors = vector<Node *>();
//     }
//     Node(int _val, vector<Node *> _neighbors)
//     {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    unordered_map<Node *, Node *> M; // 记录原结点对应的克隆节点
    Node *cloneGraph(Node *node)
    {
        // if (!node)
        //     return nullptr;
        // unordered_map<Node *, vector<int>> M1;
        // unordered_map<int, Node *> M2;
        // vector<Node *> nodes; // 记录原无向图
        // nodes.push_back(node);
        // while (!nodes.empty())
        // {
        //     Node *temp = nodes.front();
        //     nodes.erase(nodes.begin());
        //     Node *N = new Node(temp->val);
        //     M2[temp->val] = N;
        //     for (Node *x : temp->neighbors)
        //     {
        //         if (!M2.count(x->val))
        //         {
        //             nodes.push_back(x);
        //         }
        //         M1[N].push_back(x->val);
        //     }
        // }
        // for (auto elem : M1)
        // {
        //     vector<Node *> neib;
        //     for (int e : elem.second)
        //     {
        //         neib.push_back(M2[e]);
        //     }
        //     elem.first->neighbors = neib;
        // }
        // return M2[1];

        /* DFS */
        if (!node)
            return nullptr;
        if (M.count(node)) // 如果node已经被访问过了，则直接返回克隆节点
            return M[node];
        Node *N = new Node(node->val);
        M[node] = N;
        for (Node *neighbor : node->neighbors)
        {
            // 递归进行遍历所有节点
            N->neighbors.push_back(cloneGraph(neighbor));
        }
        return N;
    }
};
// @lc code=end
