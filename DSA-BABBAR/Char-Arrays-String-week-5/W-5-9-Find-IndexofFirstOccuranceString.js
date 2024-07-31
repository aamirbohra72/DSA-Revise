// Find the Index of first occurance of string 

// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.
// Example 2:

// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.


// sudoCode

 


class Solution {
    public:
        int strStr(string haystack, string needle) {
            int n = haystack.size();
            int m = needle.size();
            for(int i=0; i<=n-m; i++){
                for(int j=0; j<m; j++){
                    if(needle[j] != haystack[i+j]){
                        break;
                    }
                
                if(j == m-1){
                    return i;
                }
                }
            }
            return -1;
        }
    };


