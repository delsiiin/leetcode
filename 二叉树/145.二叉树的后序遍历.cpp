/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    /* 递归遍历 */
    // void postorder(TreeNode *root, vector<int> &res)
    // {
    //     if (!root)
    //         return;
    //     postorder(root->left, res);
    //     postorder(root->right, res);
    //     res.push_back(root->val);
    // }

    // vector<int> postorderTraversal(TreeNode *root)
    // {
    //     vector<int> res;
    //     postorder(root, res);
    //     return res;
    // }

    /* 迭代遍历 */
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> S;
        TreeNode *pre = nullptr;
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
            if (!root->right || root->right == pre) // 后序遍历关键条件
            {
                pre = root;
                res.push_back(root->val);
                root = nullptr;
                S.pop();
            }
            else
                root = root->right;
        }
        return res;
    }
};
// @lc code=end
