/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    /* 递归遍历 */
    // void preorder(TreeNode *root, vector<int> &res)
    // {
    //     if (root)
    //     {
    //         res.push_back(root->val);
    //     }
    //     else
    //     {
    //         return;
    //     }
    //     preorder(root->left, res);
    //     preorder(root->right, res);
    // }

    // vector<int> preorderTraversal(TreeNode *root)
    // {
    //     vector<int> res;
    //     preorder(root, res);
    //     return res;
    // }

    /* 迭代遍历 */
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        stack<TreeNode *> S;
        vector<int> res;
        while (!S.empty() || root) // 判断条件很重要
        {
            while (root) // 先遍历完左子树
            {
                res.push_back(root->val);
                S.push(root);
                root = root->left;
            }
            root = S.top();
            S.pop();
            root = root->right; // 左子树和根遍历完成后再遍历右子树
        }
        return res;
    }
};
// @lc code=end
