// Problem Description

// Given an array A of length N. Also given are integers B and C.

// Return 1 if there exists a subarray with length B having sum C and 0 otherwise



// Problem Constraints

// 1 <= N <= 105

// 1 <= A[i] <= 104

// 1 <= B <= N

// 1 <= C <= 109

// Example Input

// Input 1:


// A = [4, 3, 2, 6, 1]
// B = 3
// C = 11
// Input 2:

// A = [4, 2, 2, 5, 1]
// B = 4
// C = 6




// Example Output

// Output 1:
// 1
// Output 2:

// 0


int Solution::solve(vector<int> &A, int B, int C) {
    int sum = 0;
    int ans = 0;
    for(int i=0; i< B; i++){
        sum += A[i];
    }
        // cout<< sum << "got sum"<<endl;
    ans = sum;
    int n = A.size();
    int i = 1, j = B;
    while(j < n){
        sum = sum - A[i-1] + A[j];
        // ans = max(ans, sum);
        i++; j++;
    }
    //  cout<< sum << " value of sum"<< endl;
     if(sum == C){
         return 1;
     }else{
         return 0;
     }
    
}
