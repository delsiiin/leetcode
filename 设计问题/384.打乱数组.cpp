/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    Solution(vector<int> &nums)
    {
        this->nums = nums;
        this->origin = nums;
    }

    vector<int> reset()
    {
        return origin;
    }

    vector<int> shuffle()
    {
        vector<int> res;
        while (!nums.empty())
        {
            int index = rand() % nums.size(); // 随机一个索引，将对应元素放入res中
            res.push_back(nums[index]);
            nums.erase(nums.begin() + index); // 删除原数组中的该元素
        }
        nums = origin;
        return res;
    }

private:
    vector<int> nums;
    vector<int> origin;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end
