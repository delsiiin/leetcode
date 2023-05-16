/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        // 双指针解法（也可考虑二分查找或哈希表）
        int left = 0, right = numbers.size() - 1;
        while (left < right && left != right)
        {
            if (numbers[left] + numbers[right] == target)
                return {left + 1, right + 1};
            else if (numbers[left] + numbers[right] > target)
                right--;
            else
                left++;
        }
        return {};

        // 二分查找
        // int left, right = numbers.size() - 1;
        // for (int i = 0; i < numbers.size(); i++)
        // {
        //     left = i + 1;
        //     while (left <= right)
        //     {
        //         int mid = (left + right) / 2;
        //         if (numbers[mid] == target - numbers[i])
        //             return {i + 1, mid + 1};
        //         else if (numbers[mid] > target - numbers[i])
        //         {
        //             right = mid - 1;
        //         }
        //         else
        //         {
        //             left = mid + 1;
        //         }
        //     }
        // }
        // return {};
    }
};
// @lc code=end
