/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
class Solution
{
public:
    bool cmp(TreeNode *left, TreeNode *right)
    {
        if ((!left && right) || (left && !right)) // 一空一不空直接报错
            return false;
        if (left && right && left->val != right->val) // 两个都不空则比较大小是否一致
            return false;
        if (!left && !right) // 两个都空则代表递归结束，返回true
            return true;
        return cmp(left->left, right->right) && cmp(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root || (!root->left && !root->right)) // 判断根节点是否为空或者只有根节点
            return true;
        return cmp(root->left, root->right);
    }
};
// @lc code=end
