// Problem Description

// Given an array A, find the size of the smallest subarray such that it contains at least one occurrence of the maximum value of the array

// and at least one occurrence of the minimum value of the array.



// Problem Constraints

// 1 <= |A| <= 2000

// Example Input

// Input 1:

// A = [1, 3, 2]
// Input 2:

// A = [2, 6, 1, 6, 9]


// Example Output

// Output 1:

//  2
// Output 2:

//  3


// Example Explanation

// Explanation 1:

//  Take the 1st and 2nd elements as they are the minimum and maximum elements respectievly.
// Explanation 2:

//  Take the last 3 elements of the array.


 int Solution::solve(vector<int> &A) {
    int mini = -1;
    int maxi = -1;
    int minvalue = INT_MAX;
    int maxvalue = INT_MIN;
    int len = 0;
    int ans = A.size();
     
     for(int i=0; i< A.size(); i++){
         minvalue = min(minvalue, A[i]);
        //  cout<<minvalue<<endl;
         maxvalue = max(maxvalue, A[i]);
        //  cout<<maxvalue<<endl;
     }

    for(int i= A.size()-1; i>=0; i--){
        if(A[i] == minvalue){
            mini = i;
        
        if(maxi != -1){
            len = abs(maxi - mini + 1);
            ans = min(ans, len);
        }
        }
        if(A[i] == maxvalue){
            maxi = i;
            if(mini != -1){
                len = abs(mini - maxi + 1);
                ans = min(ans, len);
            }
        }

    }
    return ans;
}
