// 748. Shortest Completing Word

// Given a string licensePlate and an array of strings words, find the shortest completing word in words.

// A completing word is a word that contains all the letters in licensePlate. Ignore numbers and spaces in licensePlate, and treat letters as case insensitive. If a letter appears more than once in licensePlate, then it must appear in the word the same number of times or more.

// For example, if licensePlate = "aBc 12c", then it contains letters 'a', 'b' (ignoring case), and 'c' twice. Possible completing words are "abccdef", "caaacab", and "cbca".

// Return the shortest completing word in words. It is guaranteed an answer exists. If there are multiple shortest completing words, return the first one that occurs in words.

// Example 1:

// Input: licensePlate = "1s3 PSt", words = ["step","steps","stripe","stepple"]
// Output: "steps"
// Explanation: licensePlate contains letters 's', 'p', 's' (ignoring case), and 't'.
// "step" contains 't' and 'p', but only contains 1 's'.
// "steps" contains 't', 'p', and both 's' characters.
// "stripe" is missing an 's'.
// "stepple" is missing an 's'.
// Since "steps" is the only word containing all the letters, that is the answer.

// Example 2:

// Input: licensePlate = "1s3 456", words = ["looks","pest","stew","show"]
// Output: "pest"
// Explanation: licensePlate only contains the letter 's'. All the words contain 's', but among these "pest", "stew", and "show" are shortest. The answer is "pest" because it is the word that appears earliest of the 3.

// Constraints:

//     1 <= licensePlate.length <= 7
//     licensePlate contains digits, letters (uppercase or lowercase), or space ' '.
//     1 <= words.length <= 1000
//     1 <= words[i].length <= 15
//     words[i] consists of lower case English letters.

// Solution 1 : hashmap
class Solution
{
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {
        std::unordered_map<char, int> charMap;
        for (const auto &ch : licensePlate)
        {
            if (std::isalpha(ch))
            {
                charMap[std::tolower(ch)]++;
            }
        }

        std::string ret = "";
        for (const auto &word : words)
        {
            std::unordered_map<char, int> wordMap;
            for (const auto &ch : word)
            {
                wordMap[ch]++;
            }

            bool isValid = true;
            for (const auto &pair : charMap)
            {
                if (wordMap[pair.first] < charMap[pair.first])
                {
                    isValid = false;
                    break;
                }
            }

            if (isValid && (ret == "" || word.size() < ret.size()))
            {
                ret = word;
            }
        }

        return ret;
    }
};

// Solution 2 : vector
class Solution
{
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {
        std::vector<int> plateFreq(26, 0);

        for (char c : licensePlate)
        {
            if (std::isalpha(c))
            {
                plateFreq[std::tolower(c) - 'a']++;
            }
        }

        std::string result;
        for (const std::string &word : words)
        {
            std::vector<int> wordFreq(26, 0);
            for (char c : word)
            {
                wordFreq[std::tolower(c) - 'a']++;
            }

            bool isValid = true;
            for (int i = 0; i < 26; ++i)
            {
                if (wordFreq[i] < plateFreq[i])
                {
                    isValid = false;
                    break;
                }
            }

            if (isValid && (result.empty() || word.length() < result.length()))
            {
                result = word;
            }
        }

        return result;
    }
};
