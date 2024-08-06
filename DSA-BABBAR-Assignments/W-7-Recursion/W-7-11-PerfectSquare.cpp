//TLE go with Dp solution

class Solution {
    public:
    
        int numSquareHelper(int n){
            //base case 
            if(n ==0){
                return 1;
            }
            if(n<0){
                return 0;
            }
            int ans = INT_MAX;
            int i = 1;
            int end = sqrt(n);
            while(i<=end){
                int perfectSquare = i*i;
                int numberofPerfectSquare = 1 + numSquareHelper(n- perfectSquare);
                if(numberofPerfectSquare < ans){
                    ans = numberofPerfectSquare;
                }
                i++;
            }
            return ans;
        }
    
    
    
        int numSquares(int n) {
            return numSquareHelper(n) - 1;
            
        }
    };