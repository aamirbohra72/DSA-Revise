// Brothers From Different Roots
// Difficulty: EasyAccuracy: 53.04%Submissions: 62K+Points: 2
// Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x, your task is to complete the function countPairs(), that returns the count of all pairs of (a, b), where a belongs to one BST and b belongs to another BST, such that a + b = x.

// Example 1:

// Input:
// BST1:
//        5
//      /   \
//     3     7
//    / \   / \
//   2   4 6   8
// BST2:
//        10
//      /    \
//     6      15
//    / \    /  \
//   3   8  11   18
// x = 16
// Output:
// 3
// Explanation:
// The pairs are: (5, 11), (6, 10) and (8, 8)
// Example 2:

// Input:
// BST1:
//   1
//    \
//     3
//    /
//   2
// BST2:
//     3
//    / \
//   2   4
//  /     
// 1
// x = 4
// Output:
// 3
// Explanation:
// The pairs are: (2, 2), (3, 1) and (1, 3)
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function countPairs(), which takes two BST's as parameter in the form of root1 and root2 and the integer x, that returns the count of all pairs from both the BSTs whose sum is equal to x.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ Number of nodes ≤ 105
// 1 ≤ Data of a node ≤ 106 1000000
// 1 ≤ X ≤ 2*106 

class Solution
{
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        int ans = 0;
        stack<Node*> s1, s2;
        Node* a = root1;
        Node* b = root2;
        
        // Infinite loop replaced by a proper condition
        while (true) {
            // Traverse the left subtree of root1 and push nodes to stack s1
            while (a) {
                s1.push(a);
                a = a->left;
            }
            // Traverse the right subtree of root2 and push nodes to stack s2
            while (b) {
                s2.push(b);
                b = b->right;
            }
            
            // Check if either stack is empty
            if (s1.empty() || s2.empty()) {
                break;
            }
            
            Node* atop = s1.top();
            Node* btop = s2.top();
            
            int sum = atop->data + btop->data;
            
            if (sum == x) {
                ++ans;
                s1.pop();
                s2.pop();
                // Move to the next nodes
                a = atop->right;
                b = btop->left;
            } else if (sum < x) {
                s1.pop();
                a = atop->right;
            } else {
                s2.pop();
                b = btop->left;
            }
        }
        
        return ans;
    }
};

