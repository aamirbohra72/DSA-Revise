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
    // Never forget put & before ans
    
        void solve(TreeNode* root, int targetSum, int currSum, vector<int>&path, vector<vector<int>>&ans){
            //root 
            if(root == NULL){
                return;
            }
    
            // leaf Node
            if(root->left == NULL && root->right == NULL){
                path.push_back(root->val);
                currSum += root->val;
                if(currSum == targetSum){
                    ans.push_back(path);
                }
                path.pop_back();
                currSum -= root->val;
                return;
        }
    
        //include current Node
    
        path.push_back(root->val);
        currSum +=root->val;
    
        solve(root->left, targetSum, currSum, path, ans);
        solve(root->right, targetSum, currSum, path, ans);
    
        //backtrack because of address pass kiya he path me
        path.pop_back();
        currSum -= root->val;
        
        }
    
        vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
            vector<int>temp;
            int sum = 0;
            vector<vector<int>>ans;
            solve(root, targetSum, sum , temp , ans);
            return ans;
            
        }
    };


    // -----------------------------Path-Sum-2 -----------------------------------------
//     Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// Output: [[5,4,11,2],[5,8,4,5]]
// Explanation: There are two paths whose sum equals targetSum:
// 5 + 4 + 11 + 2 = 22
// 5 + 8 + 4 + 5 = 22

// Example:2 Input: root = [1,2,3], targetSum = 5
// Output: false
// Explanation: There two root-to-leaf paths in the tree:
// (1 --> 2): The sum is 3.
// (1 --> 3): The sum is 4.
// There is no root-to-leaf path with sum = 5.

// Example:3 Input: root = [], targetSum = 0
// Output: false
// Explanation: Since the tree is empty, there are no root-to-leaf paths.