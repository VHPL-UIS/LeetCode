// 49. Group Anagrams

// Given an array of strings strs, group the

// together. You can return the answer in any order.

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]

// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Explanation:

//     There is no string in strs that can be rearranged to form "bat".
//     The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
//     The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

// Example 2:

// Input: strs = [""]

// Output: [[""]]

// Example 3:

// Input: strs = ["a"]

// Output: [["a"]]

// Constraints:

//     1 <= strs.length <= 104
//     0 <= strs[i].length <= 100
//     strs[i] consists of lowercase English letters.

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> groups;

        for (const std::string &s : strs)
        {
            std::vector<int> count(26, 0);
            for (const char &c : s)
            {
                count[c - 'a']++;
            }

            std::string key;
            for (int freq : count)
            {
                key += std::to_string(freq) + '#';
            }

            groups[key].push_back(s);
        }

        std::vector<std::vector<std::string>> ret;
        for (const auto &pairs : groups)
        {
            ret.push_back(std::move(pairs.second));
        }

        return ret;
    }
};