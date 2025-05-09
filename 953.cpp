// 953. Verifying an Alien Dictionary

// In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

// Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.

// Example 1:

// Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
// Output: true
// Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

// Example 2:

// Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
// Output: false
// Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

// Example 3:

// Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
// Output: false
// Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).

// Constraints:

//     1 <= words.length <= 100
//     1 <= words[i].length <= 20
//     order.length == 26
//     All characters in words[i] and order are English lowercase letters.

class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        std::unordered_map<char, int> charMap;

        for (int i = 0; i < order.size(); ++i)
        {
            charMap[order[i]] = i;
        }

        for (int i = 0; i < words.size() - 1; ++i)
        {
            if (!isCorrectOrder(words[i], words[i + 1], charMap))
            {
                return false;
            }
        }

        return true;
    }

private:
    bool isCorrectOrder(const string &word1, const string &word2, std::unordered_map<char, int> &charMap)
    {
        int len = std::min(word1.size(), word2.size());
        for (int i = 0; i < len; ++i)
        {
            char c1 = word1[i];
            char c2 = word2[i];
            if (c1 != c2)
            {
                return charMap[c1] < charMap[c2];
            }
        }

        return word1.size() <= word2.size();
    }
};