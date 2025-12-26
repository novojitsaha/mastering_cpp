// You are given an array of distinct integers nums,
// sorted in ascending order, and an integer target.
// Implement a function to search for target within nums.
// If it exists, then return its index, otherwise, return -1.
// Your solution must run in O(logn) time.

#include <vector>

int search(std::vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + ((right - left) / 2); // this way it will not overflow

        if (target > nums[mid])
        {
            left = mid + 1;
        }
        else if (target < nums[mid])
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}