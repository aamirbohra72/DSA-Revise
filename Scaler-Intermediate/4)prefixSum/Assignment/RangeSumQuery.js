// Problem Description

// You are given an integer array A of length N.
// You are also given a 2D integer array B with dimensions M x 2, where each row denotes a [L, R] query.
// For each query, you have to find the sum of all elements from L to R indices in A (0 - indexed).
// More formally, find A[L] + A[L + 1] + A[L + 2] +... + A[R - 1] + A[R] for each query.



// Problem Constraints

// 1 <= N, M <= 105
// 1 <= A[i] <= 109
// 0 <= L <= R < N
// Example Input

// Input 1:


// A = [1, 2, 3, 4, 5]
// B = [[0, 3], [1, 2]]
// Input 2:

// A = [2, 2, 2]
// B = [[0, 0], [1, 2]]




// Example Output

// Output 1:
// [10, 5]
// Output 2:

// [2, 4]


// Example Explanation

// Explanation 1:


// The sum of all elements of A[0 ... 3] = 1 + 2 + 3 + 4 = 10.
// The sum of all elements of A[1 ... 2] = 2 + 3 = 5.
// Explanation 2:

// The sum of all elements of A[0 ... 0] = 2 = 2.
// The sum of all elements of A[1 ... 2] = 2 + 2 = 4.



vector<long long> Solution::rangeSum(vector<int> &A, vector<vector<int> > &B) {
   
    vector<long long>ans;
    vector<long long>pf(A.size() + 1, 0);
     for(int i=0; i< A.size(); i++){
  
          pf[i] = pf[i - 1] + A[i];
  }

   for(int i = 0; i < B.size(); i++){
        int l = B[i][0], r = B[i][1];
   
       long long rangeSum = pf[r] - pf[l- 1];
        
          ans.push_back(rangeSum);
   }
   return ans;



}
