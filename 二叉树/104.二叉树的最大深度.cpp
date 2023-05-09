/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <queue>
using namespace std;

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        /* 深度优先搜索 -- 递归法，先算左右子树的最大深度，再步步返回 */
        // if (root == nullptr)
        //     return 0;
        // return max(maxDepth(root->left), maxDepth(root->right)) + 1;

        /* 广度优先搜索 */
        if (root == nullptr)
            return 0;
        queue<TreeNode *> Q;
        Q.push(root);
        int depth = 0;
        while (!Q.empty()) // 判断队列是否为空
        {
            int size = Q.size(); // 每个循环重新计算队列长度（即二叉树每行有多少元素）
            while (size)
            {
                TreeNode *temp = Q.front(); // 由左向右取结点进行判断有无左右子树
                Q.pop();
                if (temp->left)
                    Q.push(temp->left);
                if (temp->right)
                    Q.push(temp->right);
                size--;
            }
            depth++; // 遍历完一层后深度加一
        }
        return depth;
    }
};
// @lc code=end
