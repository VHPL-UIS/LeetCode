// 22. Generate Parentheses

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Example 2:

// Input: n = 1
// Output: ["()"]

// Constraints:

//     1 <= n <= 8

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        std::vector<std::string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

private:
    void backtrack(std::vector<std::string> &result, std::string current, int open, int close, int max)
    {
        if (current.size() == max * 2)
        {
            result.push_back(current);
            return;
        }

        if (open < max)
        {
            backtrack(result, current + '(', open + 1, close, max);
        }

        if (close < open)
        {
            backtrack(result, current + ')', open, close + 1, max);
        }
    }
};