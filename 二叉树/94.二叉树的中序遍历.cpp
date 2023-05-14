/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    /* 递归中序遍历 */
    // void inorder(TreeNode *root, vector<int> &res)
    // {
    //     if (!root)
    //         return;
    //     inorder(root->left, res);
    //     res.push_back(root->val);
    //     inorder(root->right, res);
    // }

    // vector<int> inorderTraversal(TreeNode *root)
    // {
    //     vector<int> res;
    //     inorder(root, res);
    //     return res;
    // }

    /* 迭代中序遍历 */
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> S;
        if (!root)
            return {};
        while (!S.empty() || root)
        {
            while (root)
            {
                S.push(root);
                root = root->left;
            }
            root = S.top();
            S.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};
// @lc code=end
