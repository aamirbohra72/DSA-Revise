// 1023. Camelcase Matching
// Solved
// Medium
// Topics
// Companies
// Hint
// Given an array of strings queries and a string pattern, return a boolean array answer where answer[i] is true if queries[i] matches pattern, and false otherwise.

// A query word queries[i] matches pattern if you can insert lowercase English letters pattern so that it equals the query. You may insert each character at any position and you may not insert any characters.

 

// Example 1:

// Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
// Output: [true,false,true,true,false]
// Explanation: "FooBar" can be generated like this "F" + "oo" + "B" + "ar".
// "FootBall" can be generated like this "F" + "oot" + "B" + "all".
// "FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".
// Example 2:

// Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
// Output: [true,false,true,false,false]
// Explanation: "FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
// "FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".
// Example 3:

// Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
// Output: [false,true,false,false,false]
// Explanation: "FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".
 

// Constraints:

// 1 <= pattern.length, queries.length <= 100
// 1 <= queries[i].length <= 100
// queries[i] and pattern consist of English letters.



class Solution {
public:
    bool check(string str, string pattern) {
        int i = 0;
        int cap = 0;
        // cout << "Checking string: " << str << " against pattern: " << pattern
        //      << endl;

        for (int j = 0; j < str.size(); j++) {
            // cout << "str[" << j << "] = " << str[j] << ", pattern[" << i
            //      << "] = " << (i < pattern.size() ? pattern[i] : ' ') << endl;
            if (i < pattern.size() && str[j] == pattern[i]) {
                i++;
                // cout << "  Matched pattern[" << i - 1 << "]. Increment i -> "
                //      << i << endl;
            } else if (str[j] >= 'A' && str[j] <= 'Z') {
                cap++;
                // cout << "  Found extra uppercase: " << str[j] << ". cap -> "
                //      << cap << endl;
            }
        }
        // cout << "Final: i = " << i << ", pattern.size() = " << pattern.size()
        //      << ", cap = " << cap << endl;
        return (i == pattern.size() && cap == 0);
    }

    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = queries.size();
        vector<bool> ans(n);
        // cout << "Starting camelMatch for pattern: " << pattern << endl;

        for (int i = 0; i < queries.size(); i++) {
            // cout << "\nQuery " << i + 1 << ": " << queries[i] << endl;
            ans[i] = check(queries[i], pattern);
            // cout << "Result for query " << queries[i] << ": "
            //      << (ans[i] ? "true" : "false") << endl;
        }

        return ans;
    }
};
