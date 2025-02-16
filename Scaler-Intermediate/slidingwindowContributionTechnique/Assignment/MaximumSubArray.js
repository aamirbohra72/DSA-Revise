// Problem Description

// You are given an integer array C of size A. Now you need to find a subarray (contiguous elements) so that the sum of contiguous elements is maximum.
// But the sum must not exceed B.


// Problem Constraints

// 1 <= A <= 103
// 1 <= B <= 109
// 1 <= C[i] <= 106

// Example Input

// Input 1:
// A = 5
// B = 12
// C = [2, 1, 3, 4, 5]

// Input 2:
// A = 3
// B = 1
// C = [2, 2, 2]



int Solution::maxSubarray(int A, int B, vector<int> &C) {
    int ans = 0;
    
for(int i=0; i< C.size(); i++){
    int sum = 0;
    for(int j = i; j< C.size(); j++){
        sum += C[j];
       
          if(sum <= B)
               ans = max(ans, sum);
        // cout<<ans<<" subarray"<<"("<< i<< j<<")"<<endl;
    }
}

          return ans;
}
