/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // 结合哈希表，使用递归对每个结点的父节点进行存储
    void helper(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &M)
    {
        if (!root)
            return;
        if (root->left)
            M[root->left] = root;
        if (root->right)
            M[root->right] = root;
        helper(root->left, M);
        helper(root->right, M);
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        unordered_map<TreeNode *, TreeNode *> M;
        unordered_map<TreeNode *, int> count;
        helper(root, M);
        // 先对p进行回溯，标记已遍历的结点
        while (p != root)
        {
            count[p] = 1;
            p = M[p];
        }
        // 再对q进行回溯，遇到第一个p访问过的结点，即为二者最近公共祖先
        while (q != root)
        {
            if (count[q] == 1)
                return q;
            q = M[q];
        }
        return root;
    }
};
// @lc code=end
