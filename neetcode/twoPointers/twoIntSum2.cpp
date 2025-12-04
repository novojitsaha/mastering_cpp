// Given an array of integers numbers that is sorted in non-decreasing order.
// Return the indices (1-indexed) of two numbers, [index1, index2],
// such that they add up to a given target number target and index1 < index2.
// Note that index1 and index2 cannot be equal, therefore you may not use the same element twice.
// There will always be exactly one valid solution.
// You should aim for a solution with O(n) time and O(1) space, where n is the size of the input array.

#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &numbers, int target)
    {
        int *left = &numbers[0];
        int *right = &numbers[numbers.size() - 1];

        while (*left + *right != target)
        {
            if (*left + *right > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }

        // Convert pointers back to 1-based indices
        int index1 = static_cast<int>(left - &numbers[0]) + 1;
        int index2 = static_cast<int>(right - &numbers[0]) + 1;
        return std::vector<int>{index1, index2};
    }
};
