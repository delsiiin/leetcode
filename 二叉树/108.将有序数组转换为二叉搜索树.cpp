/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode *helper(vector<int> &num, int left, int right)
    {
        if (left > right) // 如果left大于right，则表示结点已经使用完，返回空指针结束递归
        {
            return nullptr;
        }

        int mid = (left + right + 1) / 2;          // 得到中间数的索引（奇数、偶数）
        TreeNode *root = new TreeNode(num[mid]);   // 将中间数作为根节点
        root->left = helper(num, left, mid - 1);   // 递归左子树
        root->right = helper(num, mid + 1, right); // 递归右子树
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        // 使用递归的方法，选取中间数作为每个子树的根节点
        return helper(nums, 0, nums.size() - 1);
    }
};
// @lc code=end
