/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    vector<int> tree;
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        tree.push_back(root->val);
        inorder(root->right);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        // 中序遍历二叉搜索树得到升序数组，返回第k位
        inorder(root);
        return tree[k - 1];
    }
};
// @lc code=end
