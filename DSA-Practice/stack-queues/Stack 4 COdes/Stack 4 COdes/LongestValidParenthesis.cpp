// 32. Longest Valid Parentheses
// Solved
// Hard
// Topics
// Companies
// Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses 
// substring
// .

 

// Example 1:

// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".
// Example 2:

// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".
// Example 3:

// Input: s = ""
// Output: 0
 

// Constraints:

// 0 <= s.length <= 3 * 104
// s[i] is '(', or ')'.


class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxLen = 0;
        
        for(int i=0; i<s.length(); i++) {
            char ch = s[i];
            if(ch == '(') {
                st.push(i);
            }
            else {
                st.pop();
                if(st.empty()) {
                    st.push(i);
                }
                else {
                    int len = i - st.top();
                    maxLen = max(len, maxLen);
                }
                
            }
        }
        return maxLen;
    }
};