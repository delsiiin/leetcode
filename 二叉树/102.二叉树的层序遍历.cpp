/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> Q;
        vector<vector<int>> res;
        TreeNode *temp;
        if (!root)
            return {};
        Q.push(root);
        while (!Q.empty())
        {
            int sz = Q.size();
            vector<int> r;
            while (sz)
            {
                temp = Q.front();
                Q.pop();
                r.push_back(temp->val);
                if (temp->left)
                    Q.push(temp->left);
                if (temp->right)
                    Q.push(temp->right);
                sz--;
            }
            res.push_back(r);
        }
        return res;
    }
};
// @lc code=end
