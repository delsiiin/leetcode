/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int slow = 0, fast = 0;
        int Min = 1e5 + 1;
        int sum = 0;
        // 定义快慢指针，当从slow加到fast大于等于target后，开始从slow按顺序减，直至sum刚好大于等于target
        // 并更新最小值。最后将得到的最小值与初始化时的值进行对比，判断最小子数组是否存在
        while (fast < nums.size())
        {
            sum += nums[fast];
            while (sum >= target)
            {
                sum -= nums[slow];
                Min = min(Min, fast - slow + 1);
                slow++;
            }
            fast++;
        }
        if (Min == 1e5 + 1)
            return 0;
        return Min;
    }
};
// @lc code=end
