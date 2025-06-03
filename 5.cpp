// 5. Longest Palindromic Substring

// Given a string s, return the longest

// in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

// Example 2:

// Input: s = "cbbd"
// Output: "bb"

 

// Constraints:

//     1 <= s.length <= 1000
//     s consist of only digits and English letters.

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty())
        {
            return "";
        }

        int start = 0, maxLen = 1;

        for (int i = 0; i < s.size(); ++i) 
        {
            expandFromCenter(s, i, i, start, maxLen);     
            expandFromCenter(s, i, i + 1, start, maxLen);
        }
        return s.substr(start, maxLen);
    }

private:
    void expandFromCenter(const std::string& s, int left, int right, int& start, int& maxLen) 
    {
        while (left >= 0 && right < s.size() && s[left] == s[right]) 
        {
            --left;
            ++right;
        }

        int len = right - left - 1; 
        if (len > maxLen) 
        {
            start = left + 1;
            maxLen = len;
        }
    }
};
