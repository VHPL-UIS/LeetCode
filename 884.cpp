// 884. Uncommon Words from Two Sentences

// A sentence is a string of single-space separated words where each word consists only of lowercase letters.

// A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

// Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.

// Example 1:

// Input: s1 = "this apple is sweet", s2 = "this apple is sour"

// Output: ["sweet","sour"]

// Explanation:

// The word "sweet" appears only in s1, while the word "sour" appears only in s2.

// Example 2:

// Input: s1 = "apple apple", s2 = "banana"

// Output: ["banana"]

// Constraints:

//     1 <= s1.length, s2.length <= 200
//     s1 and s2 consist of lowercase English letters and spaces.
//     s1 and s2 do not have leading or trailing spaces.
//     All the words in s1 and s2 are separated by a single space.

class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        std::unordered_map<std::string, int> wordMap;
        std::istringstream iss1(s1);
        std::istringstream iss2(s2);
        std::string word;

        while (iss1 >> word)
        {
            wordMap[word]++;
        }

        while (iss2 >> word)
        {
            wordMap[word]++;
        }

        std::vector<std::string> ret;
        for (const auto &pair : wordMap)
        {
            if (pair.second == 1)
            {
                ret.push_back(pair.first);
            }
        }

        return ret;
    }
};