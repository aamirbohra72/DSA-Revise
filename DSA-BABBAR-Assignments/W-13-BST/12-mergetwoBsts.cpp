// Merge two BST 's
// Difficulty: MediumAccuracy: 64.95%Submissions: 89K+Points: 4
// Given two BSTs, return elements of merged BSTs in sorted form.

// Examples :

// Input:
// BST1:
//        5
//      /   \
//     3     6
//    / \
//   2   4  
// BST2:
//         2
//       /   \
//      1     3
//             \
//              7
//             /
//            6
// Output: 1 2 2 3 3 4 5 6 6 7
// Explanation: After merging and sorting the two BST we get 1 2 2 3 3 4 5 6 6 7.
// Input:
// BST1:
//        12
//      /   
//     9
//    / \    
//   6   11
// BST2:
//       8
//     /  \
//    5    10
//   /
//  2
// Output: 2 5 6 8 9 10 11 12
// Explanation: After merging and sorting the two BST we get 2 5 6 8 9 10 11 12.
// Expected Time Complexity: O((m+n)*log(m+n))
// Expected Auxiliary Space: O(Height of BST1 + Height of BST2 + m + n)

// Constraints:
// 1 ≤ Number of Nodes, value of nodes ≤ 105


class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int>ans;
        stack<Node*>sa, sb;
        Node* a = root1, *b = root2;
        while(a || b || !sa.empty() || !sb.empty()){
            while(a){
                sa.push(a);
                a = a->left;
            }
            while(b){
                sb.push(b);
                b = b->left;
            }
            if(sb.empty() || (!sa.empty() && sa.top()->data <= sb.top()->data)){
                auto atop = sa.top();
                sa.pop();
                ans.push_back(atop->data);
                a = atop->right;
            }else{
                auto btop = sb.top();
                sb.pop();
                ans.push_back(btop->data);
                b = btop-> right;
            }
        } 
        return ans;
 
    }
};