// Maximum sum of Non-adjacent nodes
// Difficulty: MediumAccuracy: 55.35%Submissions: 71K+Points: 4
// Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that the sum of chosen nodes is maximum under a constraint that no two chosen nodes in the subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.

// Examples:

// Input:

// Output: 11
// Explanation: The maximum sum is sum of node 11.

// Input:
 
// Output: 16
// Explanation: The maximum sum is sum of nodes 1 4 5 6, i.e 16. These nodes are non adjacent.

// Constraints:
// 1 ≤ Number of nodes in the tree ≤ 104
// 1 ≤ Value of each node ≤ 105

class Solution{
  public:
  
    pair<int, int>getMaxSum_helper(Node* root){
        if(!root) return {0,0};
        auto left = getMaxSum_helper(root -> left);
        auto right = getMaxSum_helper(root -> right);
        
        int a = root -> data + left.second + right.second;
        int b = max(left.first, left.second) + max(right.first, right.second);
        return {a,b};
    }
    
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        // Add your code here
        auto ans = getMaxSum_helper(root);
        return max(ans.first, ans.second);
    }
};