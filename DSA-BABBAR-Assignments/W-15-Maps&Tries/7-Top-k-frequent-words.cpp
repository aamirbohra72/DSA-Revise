// 692. Top K Frequent Words
// Solved
// Medium
// Topics
// Companies
// Given an array of strings words and an integer k, return the k most frequent strings.

// Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

 

// Example 1:

// Input: words = ["i","love","leetcode","i","love","coding"], k = 2
// Output: ["i","love"]
// Explanation: "i" and "love" are the two most frequent words.
// Note that "i" comes before "love" due to a lower alphabetical order.
// Example 2:

// Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
// Output: ["the","is","sunny","day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
 

// Constraints:

// 1 <= words.length <= 500
// 1 <= words[i].length <= 10
// words[i] consists of lowercase English letters.
// k is in the range [1, The number of unique words[i]]


class Solution {
public:
    
    static bool cmp(pair<string, int>& a,pair<string, int>& b)
{
        if(a.second == b.second){

            int val = a.first.compare(b.first);

            if(val<0) return a.second;
            else b.second;
        }
    return a.second > b.second;

}

    vector<string> topKFrequent(vector<string>& words, int k) {

        vector<string>result;
        unordered_map<string,int>mp;

        for(auto word:words){
            mp[word]++;
        }

        // sort it according to value i.e frequency.
        vector<pair<string,int>>temp;

        for (auto& it : mp)
        {
           temp.push_back(it);
        }
            
        sort(temp.begin(),temp.end(),cmp);

        for(int i=0;i<k;i++){
         result.push_back(temp[i].first);
        }

        return result;

    }
};


          // Print the contents of `mp`
        // cout << "Contents of mp:" << endl;
        // for (auto& p : mp) {
        //     cout << "Word: " << p.first << ", Frequency: " << p.second << endl;
        // }

            //   Print the contents of the `temp` vector
        // cout << "Contents of temp before sorting:" << endl;
        // for (auto& p : temp) {
        //     cout << "Word: " << p.first << ", Frequency: " << p.second << endl;
        // }

               //  Print the contents of the `temp` vector
        // cout << "Contents of temp after sorting:" << endl;
        // for (auto& p : temp) {
        //     cout << "Word: " << p.first << ", Frequency: " << p.second << endl;
        // }

        // print result
    //     cout << "Contents of result:" << endl;
    //   for (auto& word : result) {
    //    cout << word << endl;
    //    }