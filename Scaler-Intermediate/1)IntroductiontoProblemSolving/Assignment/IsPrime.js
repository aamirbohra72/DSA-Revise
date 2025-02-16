// Problem Description

// Given a number A. Return 1 if A is prime and return 0 if not. 

// Note : 
// The value of A can cross the range of Integer.


// Problem Constraints

// 1 <= A <= 109


// Problem Description

// Given a number A. Return 1 if A is prime and return 0 if not. 

// Note : 
// The value of A can cross the range of Integer.


// Problem Constraints

// 1 <= A <= 109


int countfactors(int A){
    int count = 0;
    for(int i=1; i*i<=A; i++){
        if(A % i == 0 ){
             if(i*i == A){
                 count++ ;
             }else{
                 count += 2;
             }
        }
    }
    return count;
}


int Solution::solve(int A) {

    for(int i=2;i*i<=A; i++){
        if(countfactors(A) == 2){
            return 1;
        }else{
            return 0;
        }
    }
}
