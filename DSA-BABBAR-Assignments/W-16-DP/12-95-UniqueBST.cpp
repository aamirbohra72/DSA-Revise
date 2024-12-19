// 95. Unique Binary Search Trees II
// Solved
// Medium
// Topics
// Companies
// Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

 

// Example 1:


// Input: n = 3
// Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
// Example 2:

// Input: n = 1
// Output: [[1]]
 

// Constraints:

// 1 <= n <= 8



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
class Solution {
public:
   
   vector<TreeNode*>allPossibleBST(int start, int end){
    if(start > end) return {0};
    if(start == end) return {new TreeNode(start)};
    vector<TreeNode*>ans;
    for(int i=start; i<=end; i++){
        vector<TreeNode*>left = allPossibleBST(start, i-1);
        vector<TreeNode* > right = allPossibleBST(i+1, end);
        for(int j=0; j<left.size(); j++){
            for(int k=0; k < right.size(); k++){
                TreeNode* root = new TreeNode(i);
                root -> left = left[j];
                root -> right = right[k];
                ans.push_back(root);
            }
        }
    }

   return ans;
 }

    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return allPossibleBST(1,n);
        
    }
};