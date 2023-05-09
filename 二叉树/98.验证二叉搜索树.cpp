/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    /* 递归解决 */

    // bool Valid(TreeNode *node, long long upper, long long lower)
    // {
    //     // 对每个结点进行判断，如果为空则返回true，如果出界则返回false，若正常则继续遍历子树
    //     if (!node)
    //         return true;
    //     if (node->val <= lower || node->val >= upper)
    //         return false;
    //     return Valid(node->left, node->val, lower) && Valid(node->right, upper, node->val);
    // }

    // bool isValidBST(TreeNode *root)
    // {
    //     long long upper = pow(2, 31);      // 定义上界
    //     long long lower = -pow(2, 31) - 1; // 定义下界
    //     return Valid(root, upper, lower);
    // }

    /* 中序遍历解决：二叉搜索树中序遍历一定为升序数列 */

    bool isValidBST(TreeNode *root)
    {
        stack<TreeNode *> s;
        long long inf = -pow(2, 31) - 1;
        while (!s.empty() || root != nullptr) // 判断结点栈是否为空以及当前结点是否为空
        {
            while (root != nullptr) // 中序遍历关键！（从根节点遍历到最左子树结点，依次存入栈中）
            {
                s.push(root);
                root = root->left;
            }
            root = s.top(); // 中序遍历关键！（从最左子树结点开始往回遍历）
            s.pop();        // 将遍历过的结点从栈中删除
            if (root->val <= inf)
            {
                return false;
            }
            inf = root->val;    // 更新最小值
            root = root->right; // 中序遍历关键！（先遍历到最左子树，再判断该子树有无右子树）
        }
        return true;
    }
};
// @lc code=end
