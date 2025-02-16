// Problem Description

// Given an array A and an integer B. A pair(i, j) in the array is a good pair if i != j and (A[i] + A[j] == B). Check if any good pair exist or not.



// Problem Constraints

// 1 <= A.size() <= 104

// 1 <= A[i] <= 109

// 1 <= B <= 109



// Example Input

// Input 1:

// A = [1,2,3,4]
// B = 7
// Input 2:

// A = [1,2,4]
// B = 4
// Input 3:

// A = [1,2,2]
// B = 4


// Example Output

// Output 1:

// 1
// Output 2:

// 0
// Output 3:

// 1


// Example Explanation

// Explanation 1:

//  (i,j) = (3,4)
// Explanation 2:

// No pair has sum equal to 4.
// Explanation 3:

//  (i,j) = (2,3)





 int Solution::solve(vector<int> &A, int B) {
    for(int i=0; i< A.size()-1; i++){
       
        for(int j=0; j< A.size()-1; j++){
             if(i != j){
            if(A[i] + A[j] == B){
                return 1;
            }
        }
    }
    }
    return 0;
}
