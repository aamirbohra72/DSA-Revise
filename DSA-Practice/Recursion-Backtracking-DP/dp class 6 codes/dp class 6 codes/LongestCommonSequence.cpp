// 1143. Longest Common Subsequence
// Solved
// Medium
// Topics
// Companies
// Hint
// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

 

// Example 1:

// Input: text1 = "abcde", text2 = "ace" 
// Output: 3  
// Explanation: The longest common subsequence is "ace" and its length is 3.
// Example 2:

// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.
// Example 3:

// Input: text1 = "abc", text2 = "def"
// Output: 0
// Explanation: There is no such common subsequence, so the result is 0.
 

// Constraints:

// 1 <= text1.length, text2.length <= 1000
// text1 and text2 consist of only lowercase English characters.

//match and not match case

class Solution {
public:
    int solveUsingRecursion(string a, string b, int i, int j) {
        if(i == a.length()) {     //string khatam ho gaya to if any one , no string remain on string one
            return 0;
        }
        if(j == b.length())    //no string remain on string two
            return 0;

        int ans = 0;
        if(a[i] == b[j])
            ans =  1 + solveUsingRecursion(a,b, i+1, j+1);      //current char length include one
        else {
            ans =  0 + max(solveUsingRecursion(a,b,i,j+1),solveUsingRecursion(a,b,i+1,j));
        }
        return ans;

    } 

    //pass by reference to avoid copy of string a and b which helps to pass test cases 46/47
    int solveUsingMem(string& a, string& b, int i, int j, vector<vector<int> >& dp) {
        if(i == a.length()) {
            return 0;
        }
        if(j == b.length()) 
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if(a[i] == b[j])
            ans =  1 + solveUsingMem(a,b, i+1, j+1, dp);
        else {
            ans =  0 + max(solveUsingMem(a,b,i,j+1, dp),solveUsingMem(a,b,i+1,j, dp));
        }
        dp[i][j] =  ans;
        return dp[i][j];
    } 


    // ----------------------------------------only sufficient to memo---------------------------------------------
// steps for tabulation method, create a vector and see base case fill with zeroes, return ko bahar le jaaenge

    int solveUsingTab(string a, string b) {
        vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, 0));           //0  

        for(int i = a.length()-1; i>=0; i--) {
            for(int j = b.length()-1; j>=0; j--) {
                int ans = 0;
                if(a[i] == b[j])
                    ans =  1 + dp[i+1][j+1];
                else {
                    ans =  0 + max(dp[i][j+1], dp[i+1][j]);
                }
                dp[i][j] =  ans;
                
            }
        }
        return dp[0][0];
    }


    int solveUsingTabSO(string a, string b) {          //dp[i+1] replace kardo next se , dp[i] ko replace kardo curr se
        //vector<vector<int> > dp(a.length()+101, vector<int>(b.length()+129, 0));
        vector<int> curr(b.length()+1, 0);
        vector<int> next(b.length()+1, 0);

        for(int i = a.length()-1; i>=0; i--) {
            for(int j = b.length()-1; j>=0; j--) {
                int ans = 0;
                if(a[i] == b[j])
                    ans =  1 + next[j+1];
                else {
                    ans =  0 + max(curr[j+1], next[j]);
                }
                curr[j] =  ans;      
            }
            //shift
            next = curr;              //ise mat bhulna        curr se next tak 
        }
        return next[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // int i = 0;
        // int j = 0 ;
        // vector<vector<int> > dp(text1.length(), vector<int>(text2.length(), -1));
        // return solveUsingMem(text1, text2, i, j, dp);
        return solveUsingTabSO(text1, text2);
    }
};