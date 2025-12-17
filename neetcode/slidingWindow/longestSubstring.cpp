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
        std::unordered_map<char, int> charIdxMap;
        int longestLength{0};

        int currentLength{0};
        for (size_t i{0}; i < s.size(); i)
        {
            if (charIdxMap.count(s[i]))
            {
                i = charIdxMap[s[i]] + 1;
                if (currentLength > longestLength)
                {
                    longestLength = currentLength;
                }
                currentLength = 0;
                charIdxMap.clear();
            }
            else
            {
                charIdxMap.emplace(s[i], i);
                ++currentLength;
                ++i;
            }
        }

        return std::max(longestLength, currentLength);
    }
};
