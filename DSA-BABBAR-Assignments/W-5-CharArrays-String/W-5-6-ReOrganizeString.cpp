// 767. Reorganize String

// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

// Return any possible rearrangement of s or return "" if not possible.

 

// Example 1:

// Input: s = "aab"
// Output: "aba"
// Example 2:

// Input: s = "aaab"
// Output: ""
 

// Constraints:

// 1 <= s.length <= 500
// s consists of lowercase English letters.


class Solution {
public:
    string reorganizeString(string s) {
        
        int hash[26] = {0};
        //to avoid out of bound access loop on s.size not 26 char
        //count freq of each char
        for(int i=0;i<s.size();i++){
            hash[s[i] - 'a'] ++ ;
        }
        //find most freq char
        int max_freq_char;
        int max_freq = INT_MIN;
        for(int i=0; i<26; i++){
          if(hash[i] > max_freq){
             max_freq = hash[i];
             max_freq_char = i + 'a';    //
          }
        }
      // place most freq char at even indices
        int index = 0;
        while(max_freq > 0 && index < s.size()){
            s[index] = max_freq_char;
            max_freq--;
            index += 2;
        }
          // check if reorganization is possible
        if(max_freq != 0){
            return "";
        }
        //mark the most freq char count as zero
        hash[max_freq_char - 'a'] = 0;

        //Lets place the rest of the character 
        for(int i =0; i< 26; i++){
            while(hash[i] > 0){
                index = index >= s.size() ? 1 : index;
                s[index] = i + 'a';
                index += 2;
                hash[i]--;
            }
        }
        return s;
    }
};