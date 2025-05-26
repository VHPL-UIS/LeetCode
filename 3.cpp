// 3. Longest Substring Without Repeating Characters

// Given a string s, find the length of the longest

// without duplicate characters.

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

// Constraints:

//     0 <= s.length <= 5 * 104
//     s consists of English letters, digits, symbols and spaces.

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxLength = 0;
        int left = 0;

        std::unordered_map<char, int> charCounterMap;

        for (int right = 0; right < s.length(); ++right)
        {
            char c = s[right];
            charCounterMap[c] = charCounterMap[c] + 1;

            while (charCounterMap[c] > 1)
            {
                char leftChar = s[left];
                charCounterMap[leftChar] = charCounterMap[leftChar] - 1;
                ++left;
            }

            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};