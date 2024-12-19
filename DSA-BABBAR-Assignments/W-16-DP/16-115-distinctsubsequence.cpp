// 115. Distinct Subsequences
// Solved
// Hard
// Topics
// Companies
// Given two strings s and t, return the number of distinct subsequences of s which equals t.

// The test cases are generated so that the answer fits on a 32-bit signed integer.

 

// Example 1:

// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from s.
// rabbbit
// rabbbit
// rabbbit
// Example 2:

// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from s.
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag
  

// Constraints:

// 1 <= s.length, t.length <= 1000
// s and t consist of English letters.


class Solution {
public:
    int solveTD(string&s, string&t, int i, int j, vector<vector<int>>&dp){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(s[i] == t[j])
          ans += solveTD(s, t, i+1, j+1, dp);
          ans += solveTD(s, t, i+1, j, dp);

          return dp[i][j] =  ans;

    }
    
    int numDistinct(string s, string t) {
        // return solve(s, t, 0, 0);
        vector<vector<int>>dp(s.size()+1, vector<int>(t.size()+1, -1));
        return solveTD(s, t, 0 , 0, dp);
        
    }
};