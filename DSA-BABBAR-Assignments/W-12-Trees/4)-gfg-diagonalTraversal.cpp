// Diagonal Tree Traversal
// Difficulty: MediumAccuracy: 60.63%Submissions: 88K+Points: 4
// Given a Binary Tree, print the diagonal traversal of the binary tree.

// Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
// If the diagonal element are present in two different subtress then left subtree diagonal element should be taken first and then right subtree. 

// Example 1:

// Input :
//             8
//          /     \                                //0 -->  8, 10, 14
//         3      10                               //1---> 3,6,7,13
//       /   \      \                              //2 ---> 1,4
//      1     6     14
//          /   \   /
//         4     7 13
// Output : 8 10 14 3 6 7 13 1 4
// Explanation:
// unnamed
// Diagonal Traversal of binary tree : 
//  8 10 14 3 6 7 13 1 4
// Your Task:
// You don't need to read input or print anything. The task is to complete the function diagonal() that takes the root node as input argumets and returns the diagonal traversal of the given tree.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).
// Here N is number of nodes.

// Constraints:
// 1 <= Number of nodes<= 105
// 1 <= Data of a node<= 105


vector<int> diagonal(Node *root)
{
   // your code here
   vector<int>ans;
   if(!root) return ans;
   queue<Node*>q;
   q.push(root);
   while(!q.empty()){
       
           Node* temp = q.front(); q.pop();
           while(temp){
           ans.push_back(temp->data);
           if(temp->left){
           q.push(temp->left);
           }
           temp = temp->right;
       
           }
   }
   return ans;
}