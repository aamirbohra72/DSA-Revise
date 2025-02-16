// problem Description

// You are given an integer array A of size N.

// You have to perform B operations. In one operation, you can remove either the leftmost or the rightmost element of the array A.

// Find and return the maximum possible sum of the B elements that were removed after the B operations.

// NOTE: Suppose B = 3, and array A contains 10 elements, then you can:

// Remove 3 elements from front and 0 elements from the back, OR
// Remove 2 elements from front and 1 element from the back, OR
// Remove 1 element from front and 2 elements from the back, OR
// Remove 0 elements from front and 3 elements from the back.


// Problem Constraints

// 1 <= N <= 105

// 1 <= B <= N

// -103 <= A[i] <= 103

// Example Input

// Input 1:






//  A = [5, -2, 3 , 1, 2]
//  B = 3
// Input 2:

//  A = [ 2, 3, -1, 4, 2, 1 ]
//  B = 4







// Example Output

// Output 1:






//  8
// Output 2:

//  9







// Example Explanation

// Explanation 1:






//  Remove element 5 from front and element (1, 2) from back so we get 5 + 1 + 2 = 8
// Explanation 2:

//  Remove the first element and the last 3 elements. So we get 2 + 4 + 2 + 1 = 9


 int Solution::solve(vector<int> &A, int B) {
    
    int N = A.size(); int sum = 0; int ans = 0;
   int pSum[N]; int sSum[N - 1];
   pSum[0] = A[0];  sSum[N - 1] = A[N - 1];

    for(int i=1; i<A.size(); i++){
        pSum[i] = pSum[i - 1] + A[i];
        // cout<<pSum[i]<<"pSum"<<endl;
    }

    for(int i = N - 2; i>= 0; i--){
        sSum[i] = sSum[i + 1] + A[i];
        // cout<<sSum[i]<<"sSum"<<endl;
    }

    ans = max(pSum[B -1], sSum[N - B]);

    for(int i =1; i< B; i++){
         sum = pSum[i - 1] + sSum[N - (B - i)];
    // cout<<sum<<"ans"<<endl;
         ans = max(ans, sum);

    }
    return ans;
}
