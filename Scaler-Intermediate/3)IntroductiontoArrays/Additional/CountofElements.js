// Problem Description

// Given an array A of N integers. 
// Count the number of elements that have at least 1 elements greater than itself.


// Problem Constraints

// 1 <= N <= 105
// 1 <= A[i] <= 109


// Example Input

// Input 1:
// A = [3, 1, 2]
// Input 2:
// A = [5, 5, 3]


// Example Output

// Output 1:
// 2
// Output 2:
// 1


// Example Explanation

// Explanation 1:
// The elements that have at least 1 element greater than itself are 1 and 2
// Explanation 2:
// The elements that have at least 1 element greater than itself is 3



int Solution::solve(vector<int> &A) {
    int count = 0;
    int max = INT_MIN;

 for(int i = 0; i< A.size(); i++){
      if(A[i] > max){
            max = A[i];
      }

 }

    for(int i =0; i< A.size(); i++){
       
            if(A[i] != max){
            count++;
        }
    }
    return count;
}
