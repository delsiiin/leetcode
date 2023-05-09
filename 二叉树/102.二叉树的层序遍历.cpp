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
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<vector<int>> res = {};
        if (root == nullptr)
            return res;
        q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            res.push_back({});
            while (sz)
            {
                TreeNode *temp = q.front();
                res.back().push_back(temp->val); // 用back访问最后一个元素
                q.pop();
                if (temp->left)
                    q.push(temp->left); // 用队列进行层序遍历
                if (temp->right)
                    q.push(temp->right);
                sz--;
            }
        }
        return res;
    }
};
// @lc code=end
