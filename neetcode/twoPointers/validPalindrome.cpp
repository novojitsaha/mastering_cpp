// Given a string s, return true if it is a palindrome, otherwise return false.
// A palindrome is a string that reads the same forward and backward.
// It is also case-insensitive and ignores all non-alphanumeric characters.
// Note: Alphanumeric characters consist of letters (A-Z, a-z) and numbers (0-9).
// You should aim for a solution with O(n) time and O(1) space, where n is the length of the input string.

#include <string>
#include <cctype>

class Solution
{
public:
    bool isPalindrome(std::string s)
    {
        const char *left = s.c_str();
        const char *right = s.c_str() + s.size() - 1;

        while (right > left)
        {
            while (right > left && !std::isalnum(*right))
            {
                --right;
            }

            while (right > left && !std::isalnum(*left))
            {
                ++left;
            }

            if (std::tolower(*right) != std::tolower(*left))
            {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};
