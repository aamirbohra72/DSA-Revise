// Problem Description

// Say you have an array, A, for which the ith element is the price of a given stock on day i.
// If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

// Return the maximum possible profit.



// Problem Constraints

// 0 <= A.size() <= 700000



// 1 <= A[i] <= 107

// Example Input

// Input 1:
// A = [1, 2]
// Input 2:

// A = [1, 4, 5, 2, 4]


// Example Output

// Output 1:
// 1
// Output 2:

// 4


// Example Explanation

// Explanation 1:
// Buy the stock on day 0, and sell it on day 1.
// Explanation 2:

// Buy the stock on day 0, and sell it on day 2.



int Solution::maxProfit(const vector<int> &A) {
    int N = A.size();
    if (N <= 1) return 0; // Edge case handling

    int maxProfit = 0;
    int maxi = A[N - 1];

    for (int i = N - 2; i >= 0; i--) {
        if(A[i] > maxi){
            maxi = A[i];
        }
        // maxi = max(maxi, A[i]); // Update max selling price
        
        int profit = maxi - A[i];
        if(profit > maxProfit){
            maxProfit = profit;
        }
        // maxProfit = max(maxProfit, maxi - A[i]); // Calculate profit
    }

    return maxProfit;
}
