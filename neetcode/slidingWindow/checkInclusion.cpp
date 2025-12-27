// Permutation in String
// You are given two strings s1 and s2.
// Return true if s2 contains a permutation of s1, or false otherwise.
// That means if a permutation of s1 exists as a substring of s2, then return true.
// Both strings only contain lowercase letters.

// You should aim for a solution with O(n) time and O(1) space,
// where n is the maximum of the lengths of the two strings.

#include <string>
#include <array>
class Solution
{
public:
    bool checkInclusion(std::string s1, std::string s2)
    {
        if (s1.size() > s2.size())
            return false;

        std::array<int, 26> s1Count{0};
        std::array<int, 26> s2Count{0};
        // build character frequency map

        for (int i{0}; i < static_cast<int>(s1.size()); ++i)
        {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }
        int matches{0};
        for (int i{0}; i < 26; ++i)
        {
            if (s1Count[i] == s2Count[i])
                ++matches;
        }

        for (int left{1}, right{static_cast<int>(s1.size() )}; right < static_cast<int>(s2.size()); ++left, ++right)
        {
            if (matches == 26)
                return true;

            int indexLeft = s2[left - 1] - 'a';
            int indexRight = s2[right] - 'a';

            s2Count[indexLeft]--;
            if (s1Count[indexLeft] == s2Count[indexLeft])
            {
                ++matches;
            }
            else if (s1Count[indexLeft] - 1 == s2Count[indexLeft])
            {
                --matches;
            }

            s2Count[indexRight]++;
            if (s1Count[indexRight] == s2Count[indexRight])
            {
                ++matches;
            }
            else if (s1Count[indexRight] + 1 == s2Count[indexRight])
            {
                --matches;
            }
        }

        return matches == 26;
    }
};
