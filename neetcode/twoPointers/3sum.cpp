// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
//  where nums[i] + nums[j] + nums[k] == 0, and the indices i, j and k are all distinct.
// The output should not contain any duplicate triplets.
// You may return the output and the triplets in any order.

// You should aim for a solution with O(n^2) time and O(1) space,
// where n is the size of the input array.

#include <vector>
#include <iostream>
#include <algorithm>
class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {

        std::vector<std::vector<int>> vec;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < (int)nums.size() - 2; ++i)
        {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (right > left)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0)
                {
                    vec.push_back(std::vector<int>{nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        ++left;
                    while (left < right && nums[right] == nums[right - 1])
                        --right;
                    ++left;
                    --right;
                }
                else if (sum < 0)
                {
                    ++left;
                }
                else
                {
                    --right;
                }
            }
        }

        return vec;
    }
};

int main()
{
    std::vector<int> input = {-1, 0, 1, 2, -1, -4};
    Solution s;
}