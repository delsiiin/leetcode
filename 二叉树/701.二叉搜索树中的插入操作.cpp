/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    void helper(TreeNode *root, int val)
    {
        if (root->val > val && root->left)
        {
            helper(root->left, val);
        }
        else if (root->val < val && root->right)
        {
            helper(root->right, val);
        }
        // 前两个和后两个判断顺序不能变
        else if (root->val > val && !root->left)
        {
            TreeNode *N = new TreeNode(val);
            root->left = N;
        }
        else if (root->val < val && !root->right)
        {
            TreeNode *N = new TreeNode(val);
            root->right = N;
        }
    }

    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
        {
            TreeNode *N = new TreeNode(val);
            return N;
        }
        helper(root, val);
        return root;
    }
};
// @lc code=end
