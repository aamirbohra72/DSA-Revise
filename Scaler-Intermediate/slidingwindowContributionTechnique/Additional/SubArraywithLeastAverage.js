// Problem Description

// Given an array A of size N, find the subarray of size B with the least average.

// Problem Constraints

// 1 <= B <= N <= 105
// -105 <= A[i] <= 105

// Example Input

// Input 1:
// A = [3, 7, 90, 20, 10, 50, 40]
// B = 3
// Input 2:

// A = [3, 7, 5, 20, -10, 0, 12]
// B = 2


// Example Output

// Output 1:
// 3
// Output 2:
// 4

// Example Explanation

// Explanation 1:
// Subarray between indexes 3 and 5
// The subarray {20, 10, 50} has the least average 
// among all subarrays of size 3.
// Explanation 2:

//  Subarray between [4, 5] has minimum average



 int Solution::solve(vector<int> &A, int B) {
    int ans = 0;
    int sum = 0; 
    for(int i=0; i< B; i++){
        sum += A[i];
        
    }
        ans = sum;
        int newans = 0;
        int i = 1; int j = B;
        int n = A.size();
        while(j < n){
            sum = sum - A[i - 1] + A[j];
            if(sum < ans){
            newans = i;
            }
            ans = min(ans, sum);
            i++; j++;
        }
        // cout<<ans<<"got"<<endl;
        return newans;
}
