// You are given an array of integers temperatures where temperatures[i]
// represents the daily temperatures on the ith day.
// Return an array result where result[i] is the number of days after the
// ith day before a warmer temperature appears on a future day. If there
// is no day in the future where a warmer temperature will appear for the
//  ith day, set result[i] to 0 instead.
// You should aim for a solution as good or better than O(n) time and O(n) space, where n is the size of the input array.

#include <vector>
#include <stack>

class Solution
{
public:
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures)
    {
        // i'll use a monotonically decreasing stack
        std::stack<int> stack;
        std::vector<int> result(temperatures.size(), 0);

        for (int i = temperatures.size() - 1; i >= 0; --i)
        {
            while(!stack.empty() && temperatures[i] >= temperatures[stack.top()]){
                stack.pop();
            }
            if (!stack.empty()){
                result[i] = stack.top() - i;
            }
            stack.push(i);
        }

        return result;
    }
};
