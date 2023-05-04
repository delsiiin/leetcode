#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int i;
        int *temp = new int[nums.size()]();
        int *index = new int[nums.size()]();
        for (i = 0; i < nums.size(); i++)
        {
            temp[i] = nums[i];
        }
        for (i = 0; i < nums.size(); i++)
        {
            index[i] = (i + k) % nums.size();
            nums[index[i]] = temp[i];
        }
    }
};