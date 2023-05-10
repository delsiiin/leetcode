/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
#include <math.h>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        vector<int> isPrime(n, 1);
        int count = 0;
        if (n == 0 || n == 1)
            return 0;
        // 埃氏筛法，将已知质数的倍数标记为合数
        for (int i = 2; i < n; i++)
        {
            if (isPrime[i] == 1)
            {
                count++;
                // for (int j = 2; j * i < n; j++)
                // {
                //     isPrime[i * j] = 0;
                // }

                // 进一步优化效率
                for (long long j = (long long)i * i; j < n; j += i)
                {
                    isPrime[j] = 0;
                }
            }
        }
        return count;
    }
};
// @lc code=end
