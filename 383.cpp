// 383. Ransom Note

// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

// Each letter in magazine can only be used once in ransomNote.

// Example 1:

// Input: ransomNote = "a", magazine = "b"
// Output: false

// Example 2:

// Input: ransomNote = "aa", magazine = "ab"
// Output: false

// Example 3:

// Input: ransomNote = "aa", magazine = "aab"
// Output: true

// Constraints:

//     1 <= ransomNote.length, magazine.length <= 105
//     ransomNote and magazine consist of lowercase English letters.

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        std::unordered_map<char, int> ransomMap;

        for (const auto &ch : magazine)
        {
            ransomMap[ch]++;
        }

        for (const auto &ch : ransomNote)
        {
            if (ransomMap[ch])
            {
                ransomMap[ch]--;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};