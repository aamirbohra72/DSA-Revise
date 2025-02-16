// Problem Description

// Given an array A of N integers. Construct prefix sum of the array in the given array itself.


// Problem Constraints

// 1 <= N <= 105
// 1 <= A[i] <= 103

// Example Input

// Input 1:

// A = [1, 2, 3, 4, 5]
// Input 2:

// A = [4, 3, 2]


// Example Output

// Output 1:

// [1, 3, 6, 10, 15]
// Output 2:

// [4, 7, 9]


// Example Explanation

// Explanation 1:

// The prefix sum array of [1, 2, 3, 4, 5] is [1, 3, 6, 10, 15].
// Explanation 2:

// The prefix sum array of [4, 3, 2] is [4, 7, 9].


vector<int> Solution::solve(vector<int> &A) {
    vector<int>ans;
    
    int sum = 0;
    for(int i = 0; i < A.size(); i++){
         sum += A[i];
         ans.push_back(sum);
    }
    return ans;
}
