// Longest Substring Without Repeating Characters
// Given a string s, find the length of the longest substring without duplicate characters.
// A substring is a contiguous sequence of characters within a string.
// You should aim for a solution with O(n) time and O(m) space,
// where n is the length of the string and m is the number of unique characters in the string.

#include <string>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {

        if (s.size() < 2)
            return s.size();

        int longestLength{1}, currentLength{1}, leftPtr{0}, rightPtr{1};
        std::unordered_map<char, int> charIdxMap{{s[leftPtr], leftPtr}};

        while (rightPtr < s.size())
        {
            if (charIdxMap.count(s[rightPtr]))
            {
                longestLength = std::max(currentLength, longestLength);
                leftPtr = std::max((charIdxMap[s[rightPtr]] + 1), leftPtr) ;
                charIdxMap[s[rightPtr]] = rightPtr;
                currentLength = rightPtr - leftPtr + 1;
                ++rightPtr;
            }
            else
            {
                charIdxMap.emplace(s[rightPtr], rightPtr);
                ++rightPtr;
                ++currentLength;
            }
        }

        return std::max(longestLength, currentLength);
    }
};
