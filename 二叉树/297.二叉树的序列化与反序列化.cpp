/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

class Codec
{
public:
    void custom_serial(TreeNode *root, string &str)
    {
        // 先序遍历转存为string
        if (!root)
        {
            str += "null,";
            return;
        }
        str += to_string(root->val) + ",";
        custom_serial(root->left, str);
        custom_serial(root->right, str);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string res;
        custom_serial(root, res);
        return res;
    }

    TreeNode *custom_deserial(list<string> &s)
    {
        // 先序遍历进行还原
        if (s.front() == "null")
        {
            s.erase(s.begin());
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(s.front()));
        s.erase(s.begin());
        root->left = custom_deserial(s);
        root->right = custom_deserial(s);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        list<string> s;
        string temp;
        for (char c : data)
        {
            if (c != ',')
            {
                temp.push_back(c);
            }
            else
            {
                s.push_back(temp);
                temp.clear();
            }
        }
        return custom_deserial(s);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
