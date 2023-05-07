#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        // KMP算法需理解

        if (haystack.find(needle) != -1)
        {
            return haystack.find(needle);
        }
        else
        {
            return -1;
        }
    }
};