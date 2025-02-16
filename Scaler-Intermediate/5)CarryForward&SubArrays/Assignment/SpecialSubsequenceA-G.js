// Problem Description

// You have given a string A having Uppercase English letters.

// You have to find the number of pairs (i, j) such that A[i] = 'A', A[j] = 'G' and i < j.



// Problem Constraints

// 1 <= length(A) <= 105

// Example Input

// Input 1:

//  A = "ABCGAG"
// Input 2:

//  A = "GAB"


// Example Output

// Output 1:

//  3
// Output 2:

//  0


// Example Explanation

// Explanation 1:



//  Subsequence "AG" is 3 times in given string, the pairs are (0, 3), (0, 5) and (4, 5). 
// Explanation 2:

//  There is no subsequence "AG" in the given string.

 long Solution::solve(string A) {
    long count = 0;
    long ans = 0;
    
    for(int i=A.size()-1; i>=0; i--){
        if(A[i] == 'G'){
           count++;

        }
        else if(A[i] == 'A'){
            ans += count;
        }
    }
    return ans;
}
