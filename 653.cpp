// 653. Two Sum IV - Input is a BST

// Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

// Example 1:

// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true

// Example 2:

// Input: root = [5,3,6,2,4,null,7], k = 28
// Output: false

// Constraints:

//     The number of nodes in the tree is in the range [1, 104].
//     -104 <= Node.val <= 104
//     root is guaranteed to be a valid binary search tree.
//     -105 <= k <= 105

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        std::unordered_set<int> seen;
        return dfs(root, k, seen);
    }

private:
    bool dfs(TreeNode *node, int k, std::unordered_set<int> &seen)
    {
        if (!node)
        {
            return false;
        }

        if (seen.count(k - node->val))
        {
            return true;
        }
        seen.insert(node->val);

        return dfs(node->left, k, seen) || dfs(node->right, k, seen);
    }
};