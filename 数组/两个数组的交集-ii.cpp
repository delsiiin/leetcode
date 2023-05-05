/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums2.size() < nums1.size()) // 选取长度较小的数组进行哈希表的建立
        {
            intersect(nums2, nums1);
        }
        unordered_map<int, int> hash_map; // 未初始化全为0
        for (int num : nums1)             // for循环针对vector和数组的遍历方式，无法修改元素
        {
            hash_map[num] += 1;
        }
        vector<int> res; // 未初始化全为0
        for (int num : nums2)
        {
            if (hash_map[num] != 0 && hash_map.count(num)) // 判断哈希表中key为num的值是否存在且是否大于零
            {
                hash_map[num]--;
                res.push_back(num);     // 若满足条件，则存放进res容器中
                if (hash_map[num] == 0) // 当表中key为num的值等于0时，代表目前res中相同的num数量已经达到二者中最少，即可以删除该键值对
                {
                    hash_map.erase(num);
                }
            }
        }
        return res;
    }
};
// @lc code=end
