// BST with Dead End
// Difficulty: MediumAccuracy: 35.99%Submissions: 81K+Points: 4
// Given a Binary Search Tree that contains unique positive integer values greater than 0. The task is find if the BST contains a dead end. Here Dead End means a leaf node, at which no other integer can be inserted.

// Example 1:

// Input :   
//                8
//              /   \ 
//            5      9
//          /  \     
//         2    7 
//        /
//       1     
          
// Output : 
// Yes
// Explanation : 
// Node 1 is a Dead End in the given BST.
// Example 2:

// Input :     
//               8
//             /   \ 
//            7     10
//          /      /   \
//         2      9     13

// Output : 
// Yes
// Explanation : 
// Node 9 is a Dead End in the given BST.
// Your Task: You don't have to input or print anything. Complete the function isDeadEnd() which takes BST as input and returns a boolean value.

// Expected Time Complexity: O(N), where N is the number of nodes in the BST.
// Expected Space Complexity: O(N)

// Constraints:
// 1 <= N <= 1001
// 1 <= Value of Nodes <= 10001


class Solution{
  public:
  
  void fun(Node* root, unordered_map<int, bool>&visited, bool &ans){
      if(!root) return;
      visited[root->data] = 1;
      if(root->left == 0 && root->right == 0){
          int xp1 = root->data + 1;
          int xm1 = root->data - 1 == 0 ? root->data : root->data -1;
      
      if(visited.find(xp1) != visited.end() && visited.find(xm1) != visited.end()){
          ans += true;
          return;
      }
      }
      fun(root->left, visited, ans);
      fun(root->right, visited, ans);
  }
  
    bool isDeadEnd(Node *root)
    {
      bool ans = false;
      unordered_map<int, bool> visited;
      fun(root, visited, ans);
      return ans;
        //Your code here
    }
};
