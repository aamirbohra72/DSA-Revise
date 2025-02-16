// Problem Description

// Given an array, arr[] of size N, the task is to find the count of array indices such that removing an element from these indices makes the sum of even-indexed and odd-indexed array elements equal.



// Problem Constraints

// 1 <= N <= 105
// -105 <= A[i] <= 105
// Sum of all elements of A <= 109

// Example Input

// Input 1:
// A = [2, 1, 6, 4]
// Input 2:

// A = [1, 1, 1]






// Example Output

// Output 1:
// 1
// Output 2:

// 3






// Example Explanation

// Explanation 1:
// Removing arr[1] from the array modifies arr[] to { 2, 6, 4 } such that, arr[0] + arr[2] = arr[1]. 
// Therefore, the required output is 1. 
// Explanation 2:

// Removing arr[0] from the given array modifies arr[] to { 1, 1 } such that arr[0] = arr[1] 
// Removing arr[1] from the given array modifies arr[] to { 1, 1 } such that arr[0] = arr[1] 
// Removing arr[2] from the given array modifies arr[] to { 1, 1 } such that arr[0] = arr[1] 
// Therefore, the required output is 3.



int Solution::solve(vector<int> &A) {
    vector<int>pfe(A.size()), pfo(A.size());
     int Se, So;
      pfe[0] = A[0];
     pfo[0] = 0;
      int ans = 0;
      int n = A.size();
 
       for(int i=0; i<n; i++){
          if(i % 2 == 0){
              pfe[i] = pfe[i - 1] + A[i];
              pfo[i] = pfo[i -1];
          }else {
              pfe[i] = pfe[i - 1];
              pfo[i] = pfo[i - 1] + A[i];
          }
       }
 
      for(int i=0; i<n; i++){
          if(i  == 0){
              So = pfe[n - 1] - pfe[i];
              Se = pfo[n -1] - pfo[i];
          }else {
              So = pfo[i - 1] + (pfe[n - 1]- pfe[i]);
              Se = pfe[i - 1] + (pfo[n - 1] - pfo[i]);
          }
          if(So == Se){
              ans++;
          }
      }
      return ans;
 }
 