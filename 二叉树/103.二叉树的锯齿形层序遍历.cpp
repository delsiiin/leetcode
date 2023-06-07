/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> res;
        queue<TreeNode *> Q;
        int i = 1;
        Q.push(root);
        // 层序遍历加对奇偶层的不同处理
        while (!Q.empty())
        {
            int sz = Q.size();
            vector<int> temp;
            while (sz)
            {
                TreeNode *N = Q.front();
                Q.pop();
                temp.push_back(N->val);
                if (N->left)
                    Q.push(N->left);
                if (N->right)
                    Q.push(N->right);
                sz--;
            }
            if (i % 2 == 1)
                res.push_back(temp);
            else
            {
                reverse(temp.begin(), temp.end());
                res.push_back(temp);
            }
            i++;
        }
        return res;
    }
};
// @lc code=end
