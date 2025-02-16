// Problem Description

// You are given an integer array A. You have to find the second largest element/value in the array or report that no such element exists.


// Problem Constraints

// 1 <= |A| <= 105


// 0 <= A[i] <= 109


// Example Input

// Input 1:

//  A = [2, 1, 2] 
// Input 2:

//  A = [2]


// Example Output

// Output 1:

//  1 
// Output 2:

//  -1 


// Example Explanation

// Explanation 1:

//  First largest element = 2
//  Second largest element = 1
// Explanation 2:

//  There is no second largest element in the array.



 int Solution::solve(vector<int> &A) {
    int maxi = A[0];
    int SecondElement = -1;
    for(int i=0; i< A.size(); i++){

      // if all elements are same & if only single element write edge cases
        
    

        if(A[i] > maxi){
            SecondElement =  maxi;
            maxi = A[i];       //update
        }
    
        else if(A[i] < maxi && A[i] > SecondElement){
        SecondElement = A[i];
        }
        
        }

         if(SecondElement == -1 ){
            return -1;
        }
        
    
    return SecondElement;
}
