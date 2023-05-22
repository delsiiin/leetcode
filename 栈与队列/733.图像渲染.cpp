/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    void helper(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int temp = image[sr][sc];
        image[sr][sc] = color;
        if (sr - 1 >= 0 && image[sr - 1][sc] == temp)
        {
            helper(image, sr - 1, sc, color);
        }
        if (sr + 1 < image.size() && image[sr + 1][sc] == temp)
        {

            helper(image, sr + 1, sc, color);
        }
        if (sc - 1 >= 0 && image[sr][sc - 1] == temp)
        {

            helper(image, sr, sc - 1, color);
        }
        if (sc + 1 < image[0].size() && image[sr][sc + 1] == temp)
        {

            helper(image, sr, sc + 1, color);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        if (image[sr][sc] != color) // 判断修改后与修改前是否有变化
            helper(image, sr, sc, color);
        return image;
    }
};
// @lc code=end
