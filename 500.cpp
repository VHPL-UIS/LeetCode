// 500. Keyboard Row

// Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.

// Note that the strings are case-insensitive, both lowercased and uppercased of the same letter are treated as if they are at the same row.

// In the American keyboard:

//     the first row consists of the characters "qwertyuiop",
//     the second row consists of the characters "asdfghjkl", and
//     the third row consists of the characters "zxcvbnm".

// Example 1:

// Input: words = ["Hello","Alaska","Dad","Peace"]

// Output: ["Alaska","Dad"]

// Explanation:

// Both "a" and "A" are in the 2nd row of the American keyboard due to case insensitivity.

// Example 2:

// Input: words = ["omk"]

// Output: []

// Example 3:

// Input: words = ["adsdf","sfd"]

// Output: ["adsdf","sfd"]

// Constraints:

//     1 <= words.length <= 20
//     1 <= words[i].length <= 100
//     words[i] consists of English letters (both lowercase and uppercase).

class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        std::unordered_set<char> row1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        std::unordered_set<char> row2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        std::unordered_set<char> row3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};

        std::vector<std::string> retStringVec;

        for (const string &word : words)
        {
            std::unordered_set<char> *row = nullptr;
            char first = std::tolower(word[0]);

            if (row1.count(first))
            {
                row = &row1;
            }
            else if (row2.count(first))
            {
                row = &row2;
            }
            else if (row3.count(first))
            {
                row = &row3;
            }

            bool isValid = true;
            for (char c : word)
            {
                if (!row->count(std::tolower(c)))
                {
                    isValid = false;
                    break;
                }
            }

            if (isValid)
            {
                retStringVec.push_back(word);
            }
        }

        return retStringVec;
    }
};