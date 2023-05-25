/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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

class BSTIterator
{
public:
    BSTIterator(TreeNode *root)
    {
        stack<TreeNode *> Stack;
        index = 0;
        while (!Stack.empty() || root)
        {
            while (root)
            {
                Stack.push(root);
                root = root->left;
            }
            TreeNode *temp = Stack.top();
            Stack.pop();
            BST.push_back(temp->val);
            root = temp->right;
        }
    }

    int next()
    {
        if (hasNext())
        {
            int res = BST[index];
            index++;
            return res;
        }
        return -1;
    }

    bool hasNext()
    {
        if (index < BST.size())
        {
            return true;
        }
        return false;
    }

private:
    vector<int> BST;
    int index;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
