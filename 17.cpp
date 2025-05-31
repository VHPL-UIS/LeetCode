// 17. Letter Combinations of a Phone Number

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

// Example 2:

// Input: digits = ""
// Output: []

// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]

// Constraints:

//     0 <= digits.length <= 4
//     digits[i] is a digit in the range ['2', '9'].

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return {};
        }

        std::unordered_map<char, std::string> numberMap;
        numberMap['2'] = "abc";
        numberMap['3'] = "def";
        numberMap['4'] = "ghi";
        numberMap['5'] = "jkl";
        numberMap['6'] = "mno";
        numberMap['7'] = "pqrs";
        numberMap['8'] = "tuv";
        numberMap['9'] = "wxyz";

        std::vector<std::string> allCombinations{""};
        for (const char &digit : digits)
        {
            std::vector<std::string> combinations;
            for (const auto &comb : allCombinations)
            {
                std::string letters = numberMap[digit];
                for (const char &letter : letters)
                {
                    combinations.push_back(comb + letter);
                }
            }
            allCombinations.swap(combinations);
        }

        return allCombinations;
    }
};