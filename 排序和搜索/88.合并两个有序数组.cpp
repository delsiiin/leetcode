/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        /* 直接插入后排序 */
        // int i;
        // for (i = 0; i < n && n; i++)
        // {
        //     nums1[m] = nums2[i];
        //     m++;
        // }
        // sort(nums1.begin(), nums1.end());

        /* 双指针法 */
        int cursor1 = 0, cursor2 = 0;
        vector<int> res;
        while (cursor1 != m && cursor2 != n)
        {
            if (nums1[cursor1] <= nums2[cursor2])
            {
                res.push_back(nums1[cursor1++]);
            }
            else
            {
                res.push_back(nums2[cursor2++]);
            }
        }
        if (cursor1 == m)
        {
            while (cursor2 != n)
            {
                res.push_back(nums2[cursor2++]);
            }
        }
        else
        {
            while (cursor1 != m)
            {
                res.push_back(nums1[cursor1++]);
            }
        }
        nums1 = res;
    }
};
// @lc code=end
