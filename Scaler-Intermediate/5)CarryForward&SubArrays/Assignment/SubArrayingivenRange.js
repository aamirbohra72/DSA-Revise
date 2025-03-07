// Problem Description

// Given an array A of length N, return the subarray from B to C.


// Problem Constraints

// 1 <= N <= 105

// 1 <= A[i] <= 109

// 0 <= B <= C < N

// Example Input

// Input 1:
// A = [4, 3, 2, 6]
// B = 1
// C = 3
// Input 2:

// A = [4, 2, 2]
// B = 0
// C = 1


// Example Output

// Output 1:
// [3, 2, 6]
// Output 2:

// [4, 2]


// Example Explanation

// Explanation 1:
// The subarray of A from 1 to 3 is [3, 2, 6].
// Explanation 2:
// The subarray of A from 0 to 1 is [4, 2].



vector<int> Solution::solve(vector<int> &A, int B, int C) {
    vector<int>ans;
    for(int i=B; i<=C; i++){
        ans.push_back(A[i]);
    }
    return ans;
}
