/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    unordered_map<TreeNode *, int> M;
    int flag = 0;
    int depth(TreeNode *root)
    {
        if (!root)
            return 0;
        int dep = 1 + max(depth(root->left), depth(root->right));
        M[root] = dep;
        return dep;
    }
    void firstorder(TreeNode *root)
    {
        if (!root)
            return;
        if (abs(M[root->left] - M[root->right]) > 1)
        {
            flag = 1;
        }
        firstorder(root->left);
        firstorder(root->right);
    }

    bool isBalanced(TreeNode *root)
    {
        int dep = depth(root);
        firstorder(root);
        if (flag == 1)
            return false;
        return true;
    }
};
// @lc code=end
