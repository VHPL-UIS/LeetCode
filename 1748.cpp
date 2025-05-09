// 1748. Sum of Unique Elements

// You are given an integer array nums. The unique elements of an array are the elements that appear exactly once in the array.

// Return the sum of all the unique elements of nums.

// Example 1:

// Input: nums = [1,2,3,2]
// Output: 4
// Explanation: The unique elements are [1,3], and the sum is 4.

// Example 2:

// Input: nums = [1,1,1,1,1]
// Output: 0
// Explanation: There are no unique elements, and the sum is 0.

// Example 3:

// Input: nums = [1,2,3,4,5]
// Output: 15
// Explanation: The unique elements are [1,2,3,4,5], and the sum is 15.

// Constraints:

//     1 <= nums.length <= 100
//     1 <= nums[i] <= 100

class Solution
{
public:
    int sumOfUnique(vector<int> &nums)
    {
        std::unordered_map<int, int> numsMap;
        for (const auto &num : nums)
        {
            numsMap[num] = numsMap[num] + 1;
        }

        int sum = 0;

        for (const auto &pair : numsMap)
        {
            if (pair.second == 1)
            {
                sum += pair.first;
            }
        }

        return sum;
    }
};