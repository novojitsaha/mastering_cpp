// You are given an array of integers heights where heights[i] represents
//  the height of a bar. The width of each bar is 1.
// Return the area of the largest rectangle that can be formed among the bars.
// You should aim for a solution with O(n) time and O(n) space, where n is the size of the input array.

#include <vector>
#include <stack>
#include <algorithm>

class Solution
{
public:
    int largestRectangleArea(std::vector<int> &heights)
    {
        std::stack<int> stack;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; ++i)
        {
            int currentHeight = i == n ? 0 : heights[i];

            while (!stack.empty() && currentHeight < heights[stack.top()])
            {
                int poppedHeight = heights[stack.top()];
                stack.pop();
                int width = stack.empty() ? i : i - stack.top() - 1;
                int area = poppedHeight * width;
                maxArea = std::max(area, maxArea);
            }

            stack.push(i);
        }
        return maxArea;
    }
};
