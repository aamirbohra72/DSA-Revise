// 337. House Robber III
// Solved
// Medium
// Topics
// Companies
// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

// Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

// Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

 

// Example 1:


// Input: root = [3,2,3,null,3,null,1]
// Output: 7
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
// Example 2:


// Input: root = [3,4,5,1,3,null,1]
// Output: 9
// Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// 0 <= Node.val <= 104

class Solution {
public:
    int solve(TreeNode* root, unordered_map<TreeNode*, int>& dp) {
        if (!root) return 0;

        // Check if result is already in the memoization table
        if (dp.find(root) != dp.end()) return dp[root];

        int robthehouse = root->val;
        int dontrobthehouse = 0;

        // If robbing this house, skip its immediate children
        if (root->left) {
            robthehouse += solve(root->left->left, dp) + solve(root->left->right, dp);
        }
        if (root->right) {
            robthehouse += solve(root->right->left, dp) + solve(root->right->right, dp);
        }

        // If not robbing this house, consider its immediate children
        dontrobthehouse = solve(root->left, dp) + solve(root->right, dp);

        // Store the result in the memoization table
        dp[root] = max(robthehouse, dontrobthehouse);
        return dp[root];
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return solve(root, dp);
    }
};
