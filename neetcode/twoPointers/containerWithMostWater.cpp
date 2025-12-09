// You are given an integer array heights where heights[i] represents the height of the ith bar.
// You may choose any two bars to form a container. Return the maximum amount of water a container can store.
// You should aim for a solution with O(n) time and O(1) space, where n is the size of the input array.

#include <vector>
#include <algorithm>

int maxArea(std::vector<int> &heights)
{

    int maxArea = 0;

    int left = 0;
    int right = heights.size() - 1;

    while (right > left)
    {
        int height = std::min(heights[left], heights[right]);
        int width = right - left;
        int area = height * width;
        maxArea = std::max(area, maxArea);

        if (heights[left] < heights[right])
        {
            ++left;
        }
        else
        {
            --right;
        }
        
    }

    return maxArea;
}
