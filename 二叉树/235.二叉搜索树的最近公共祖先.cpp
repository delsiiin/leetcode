/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 依据二叉搜索树特性，只需遍历一次即能找到最近公共祖先
        if (root->val > q->val && root->val > p->val)
            return lowestCommonAncestor(root->left, p, q);
        else if (root->val < q->val && root->val < p->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
};
// @lc code=end
