// 804. Unique Morse Code Words

// International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows:

//     'a' maps to ".-",
//     'b' maps to "-...",
//     'c' maps to "-.-.", and so on.

// For convenience, the full table for the 26 letters of the English alphabet is given below:

// [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]

// Given an array of strings words where each word can be written as a concatenation of the Morse code of each letter.

//     For example, "cab" can be written as "-.-..--...", which is the concatenation of "-.-.", ".-", and "-...". We will call such a concatenation the transformation of a word.

// Return the number of different transformations among all words we have.

// Example 1:

// Input: words = ["gin","zen","gig","msg"]
// Output: 2
// Explanation: The transformation of each word is:
// "gin" -> "--...-."
// "zen" -> "--...-."
// "gig" -> "--...--."
// "msg" -> "--...--."
// There are 2 different transformations: "--...-." and "--...--.".

// Example 2:

// Input: words = ["a"]
// Output: 1

// Constraints:

//     1 <= words.length <= 100
//     1 <= words[i].length <= 12
//     words[i] consists of lowercase English letters.

class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        std::unordered_map<char, std::string> morseMap;
        morseMap['a'] = ".-";
        morseMap['b'] = "-...";
        morseMap['c'] = "-.-.";
        morseMap['d'] = "-..";
        morseMap['e'] = ".";
        morseMap['f'] = "..-.";
        morseMap['g'] = "--.";
        morseMap['h'] = "....";
        morseMap['i'] = "..";
        morseMap['j'] = ".---";
        morseMap['k'] = "-.-";
        morseMap['l'] = ".-..";
        morseMap['m'] = "--";
        morseMap['n'] = "-.";
        morseMap['o'] = "---";
        morseMap['p'] = ".--.";
        morseMap['q'] = "--.-";
        morseMap['r'] = ".-.";
        morseMap['s'] = "...";
        morseMap['t'] = "-";
        morseMap['u'] = "..-";
        morseMap['v'] = "...-";
        morseMap['w'] = ".--";
        morseMap['x'] = "-..-";
        morseMap['y'] = "-.--";
        morseMap['z'] = "--..";

        std::unordered_set<std::string> transformationSet;
        for (const auto &word : words)
        {
            std::string morseT = "";
            for (const auto &ch : word)
            {
                morseT += morseMap[ch];
            }

            transformationSet.insert(morseT);
        }

        return transformationSet.size();
    }
};