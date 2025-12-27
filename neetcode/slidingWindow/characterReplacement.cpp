// Longest Repeating Character Replacement
// You are given a string s consisting of only uppercase english characters and an integer k.
// You can choose up to k characters of the string and replace them with any other uppercase
// English character. After performing at most k replacements, return the length of the longest
// substring which contains only one distinct character.
// You should aim for a solution with O(n) time and O(m) space, where n is the length of the
//  given string and m is the number of unique characters in the string.

#include <string>
#include <algorithm>
#include <unordered_map>

int characterReplacement(std::string s, int k)
{
    std::unordered_map<char, int> charFreqMap;

    int leftPtr{0}, topFreq{0}, longestLength{0};

    for (int rightPtr{0}; rightPtr < s.size(); ++rightPtr)
    {
        charFreqMap[s[rightPtr]]++;
        topFreq = std::max(topFreq, charFreqMap[s[rightPtr]]);

        if ((rightPtr - leftPtr + 1) - topFreq > k)
        {
            charFreqMap[s[leftPtr]]--;
            leftPtr++;
        }
        longestLength = std::max(longestLength, (rightPtr - leftPtr + 1));
    }

    return longestLength;
}