/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
#include <unordered_map>
using namespace std;

class Solution
{
    int pre_index;
    unordered_map<int, int> m;

public:
    // 参照中后序构造二叉树
    TreeNode *helper(vector<int> &preorder, int in_left, int in_right)
    {
        if (in_left > in_right)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[pre_index++]);
        int index = m[root->val];
        root->left = helper(preorder, in_left, index - 1);
        root->right = helper(preorder, index + 1, in_right);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        pre_index = 0;
        int i = 0;
        for (int x : inorder)
        {
            m[x] = i++;
        }
        return helper(preorder, 0, inorder.size() - 1);
    }
};
// @lc code=end
