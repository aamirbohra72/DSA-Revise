// Problem Description

// You will be given an integer n. You need to return the count of prime numbers less than or equal to n.


// Problem Constraints

// 0 <= n <= 10^3


// Example Input

// Input 1:
// 19
// Input 2:
// 1


// Example Output

// Output 1:
// 8
// Output 2:
// 0


// Example Explanation

// Explanation 1:
// Primes <= 19 are 2, 3, 5, 7, 11, 13, 17, 19
// Explanation 2:
// There are no primes <= 1




bool isPrime(int A){
    
    if(A < 2) return false;
    for(int i = 2; i*i<=A; i++){
        if(A % i == 0 ){
            return false;
        }
    }
    return true;

}

int Solution::solve(int n) {
    int count = 0;
    for(int i = 2; i <= n; i++){
    if(isPrime(i)){
       count++; 
   }
    }
   return count;
    
}
