/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm> // sort函数需要的库
using namespace std;

class Solution
{
public:
    bool cmp(int a, int b)
    {
        return a > b;
    }

    bool containsDuplicate(vector<int> &nums)
    {
        /* 传统冒泡速度慢 */
        // int i, j;
        // for (i = 0; i < nums.size(); i++)
        // {
        //     for (j = i + 1; j < nums.size(); j++)
        //     {
        //         if (nums[j] == nums[i])
        //         {
        //             return true;
        //         }
        //     }
        // }
        // return false;

        /* 使用sort函数先排序后比较 */
        /*
            sort函数有三个参数：第一个是起始地址，第二个是结束地址，第三个是排序方法（默认从小到大，cmp函数实现--从大到小）
         */
        sort(nums.begin(), nums.end());
        // sort(nums.begin(), nums.end(), cmp);
        int i;
        for (i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
