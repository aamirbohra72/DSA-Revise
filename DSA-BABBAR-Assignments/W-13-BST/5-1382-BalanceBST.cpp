// 1382. Balance a Binary Search Tree
// Solved
// Medium
// Topics
// Companies
// Hint
// Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

// A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

 

// Example 1:


// Input: root = [1,null,2,null,3,null,4,null,null]
// Output: [2,1,3,null,null,null,4]
// Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
// Example 2:


// Input: root = [2,1,3]
// Output: [2,1,3]
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// 1 <= Node.val <= 105




class Solution {
public:

    void inorder(TreeNode* root, vector<int>&in){
        if(!root) return ;
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
     
    TreeNode* buildTree(vector<int>&in, int start, int end){
        if(start > end) return NULL;
        int mid = (start + end) >> 1;
        TreeNode* root = new TreeNode(in[mid]);
        root -> left = buildTree(in, start, mid-1);
        root -> right = buildTree(in, mid+1, end);
        return root;

    };
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>in;
        inorder(root, in);
        return buildTree(in, 0 , in.size()-1);
        
    }
};