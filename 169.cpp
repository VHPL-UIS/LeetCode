// 169. Majority Element

// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times.
// You may assume that the majority element always exists in the array.

// Example 1:

// Input: nums = [3,2,3]
// Output: 3

// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

// Constraints:

//     n == nums.length
//     1 <= n <= 5 * 104
//     -109 <= nums[i] <= 109

// Follow-up: Could you solve the problem in linear time and in O(1) space?

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int size = nums.size();
        std::unordered_map<int, int> numsMap;
        for (auto num : nums)
        {
            numsMap[num] = numsMap[num] + 1;
        }

        int majorityCount = 0;
        int majority = -1;
        for (auto &pair : numsMap)
        {
            if (pair.second >= size / 2 && pair.second > majorityCount)
            {
                majorityCount = pair.second;
                majority = pair.first;
            }
        }

        return majority;
    }
};