// 122. Best Time to Buy and Sell Stock II
// Solved
// Medium
// Topics
// Companies
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

// Find and return the maximum profit you can achieve.

 

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.
// Example 2:

// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Total profit is 4.
// Example 3:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

// Constraints:

// 1 <= prices.length <= 3 * 104
// 0 <= prices[i] <= 104



class Solution {
public:
    int solveTD(vector<int>&prices, int i, int buy, vector<vector<int>>&dp){
        if(i >= prices.size()) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;
        if(buy){
            int buyItProfit = - prices[i] + solveTD(prices, i + 1, 0, dp);
            int skipProfit = solveTD(prices, i+1, 1, dp);
            profit =  max(buyItProfit, skipProfit);
        }else{
            int sellItProfit = prices[i] + solveTD(prices, i+1, 1, dp);
            int skipProfit = solveTD(prices, i+1, 0, dp);
            profit = max(sellItProfit, skipProfit);
        }
        dp[i][buy] =  profit;
        return dp[i][buy];
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(), vector<int> (2, -1));
        return solveTD(prices, 0, 1, dp);
        
    }
};