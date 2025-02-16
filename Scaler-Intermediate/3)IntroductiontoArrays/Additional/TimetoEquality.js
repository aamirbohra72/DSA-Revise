// Problem Description

// Given an integer array A of size N. In one second, you can increase the value of one element by 1.

// Find the minimum time in seconds to make all elements of the array equal.


// Problem Constraints

// 1 <= N <= 1000000
// 1 <= A[i] <= 1000



// Example Input

// A = [2, 4, 1, 3, 2]


// Example Output

// 8


// Example Explanation

// We can change the array A = [4, 4, 4, 4, 4]. The time required will be 8 seconds.






int Solution::solve(vector<int> &A) {
    int maxi = 0;
    for(int i = 0; i< A.size(); i++){
        if(A[i] > maxi){
            maxi = A[i];
        }
    }
    
     int sum = 0;
    for(int i=0; i< A.size(); i++){
            sum += (maxi - A[i]);
            // cout<<sum<<"give sum"<<endl;   
    }
    return sum;

}
