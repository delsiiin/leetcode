/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int count = 0;
        int i = 0, j = 0;
        int len_r = mat.size();
        int len_c = mat[0].size();
        vector<int> res(len_c * len_r);
        while (count < len_c * len_r)
        {
            // 先向右上角遍历
            while (i >= 0 && j < len_c) // 判断条件很关键
            {
                res[count++] = mat[i--][j++];
            }
            // 将索引返回到右上遍历的最后一位
            i++;
            j--;
            // 对转换对角线时的下一个元素位置进行判断
            if (j < len_c - 1)
                j++;
            else
                i++;

            // 向左下角遍历
            while (i < len_r && j >= 0)
            {
                res[count++] = mat[i++][j--];
            }
            // 将索引返回到左下遍历的最后一位
            i--;
            j++;
            // 对转换对角线时的下一个元素位置进行判断
            if (i < len_r - 1)
                i++;
            else
                j++;
        }
        return res;
    }
};
// @lc code=end
