#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        /* 从中间分为两半进行交换 */

        // int len = s.size();
        // char c;
        // int i;
        // for (i = 0; i < len / 2; i++)
        // {
        //     c = s[i];
        //     s[i] = s[len - 1 - i];
        //     s[len - 1 - i] = c;
        // }

        /* 双指针法 */
        int left = 0;
        int right = s.size() - 1;
        char c;
        int i;
        while (left != right && left - 1 != right)
        {
            // 使用swap函数更高效
            swap(s[right], s[left]);
            // c = s[right];
            // s[right] = s[left];
            // s[left] = c;
            left++;
            right--;
        }
    }
};