// 1002. Find Common Characters

// Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

// Example 1:

// Input: words = ["bella","label","roller"]
// Output: ["e","l","l"]

// Example 2:

// Input: words = ["cool","lock","cook"]
// Output: ["c","o"]

// Constraints:

//     1 <= words.length <= 100
//     1 <= words[i].length <= 100
//     words[i] consists of lowercase English letters.

class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        std::unordered_map<char, int> charMap;
        for (const auto &ch : words[0])
        {
            charMap[ch]++;
        }

        for (int i = 1; i < words.size(); ++i)
        {
            std::unordered_map<char, int> freq;
            for (const auto &ch : words[i])
            {
                freq[ch]++;
            }

            for (const auto &pair : charMap)
            {
                if (freq.count(pair.first))
                {
                    charMap[pair.first] = std::min(charMap[pair.first], freq[pair.first]);
                }
                else
                {
                    charMap[pair.first] = 0;
                }
            }
        }

        std::vector<std::string> ret;
        for (const auto &pair : charMap)
        {
            for (int i = 0; i < pair.second; ++i)
            {
                ret.push_back(std::string(1, pair.first));
            }
        }

        return ret;
    }
};