// 242. Valid Anagram

// Given two strings s and t, return true if t is an anangram of s, and false otherwise.
// An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.

// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:
// Input: s = "rat", t = "car"
// Output: false

// Constraints:

// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.

// Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (t.size() != s.size())
        {
            return false;
        }

        std::unordered_map<char, int> charMap1;
        std::unordered_map<char, int> charMap2;
        for (const auto &ch : s)
        {
            charMap1[ch] = charMap1[ch] + 1;
        }

        for (const auto &ch : t)
        {
            charMap2[ch] = charMap2[ch] + 1;
        }

        for (const auto &ch : s)
        {
            if (charMap1[ch] == charMap2[ch])
            {
                continue;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};