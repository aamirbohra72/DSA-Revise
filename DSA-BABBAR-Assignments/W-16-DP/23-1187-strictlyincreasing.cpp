// 1187. Make Array Strictly Increasing
// Solved
// Hard
// Topics
// Companies
// Hint
// Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.

// In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].

// If there is no way to make arr1 strictly increasing, return -1.

 

// Example 1:

// Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
// Output: 1
// Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
// Example 2:

// Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
// Output: 2
// Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].
// Example 3:

// Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
// Output: -1
// Explanation: You can't make arr1 strictly increasing.
 

// Constraints:

// 1 <= arr1.length, arr2.length <= 2000
// 0 <= arr1[i], arr2[i] <= 10^9


class Solution {
public:
    const int INF = 1e9; // Define a large constant for INF
    int solveTD(vector<int>&arr1, vector<int>&arr2, int prev, int i,map<pair<int, int>,int>&dp){
        if(i == arr1.size())  return 0;       //out of bound chla gya
        
        if(dp.find({prev, i}) != dp.end())  return dp[{prev, i}];
        int op1 = INF;
        if(prev < arr1[i])
            op1 = solveTD(arr1, arr2, arr1[i], i+1, dp);    //no operation

            int op2 = INF;
            auto it = upper_bound(arr2.begin(), arr2.end(), prev);
            if(it != arr2.end()){
                int index = it - arr2.begin();      //yhi game he
                //  arr1[i] = arr2[index];
                  op2 = 1 + solveTD(arr1, arr2, arr2[index], i+1, dp);  // operation happen 1 or 2
            
        }
        return dp[{prev, i}] = min(op1, op2);
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        // return solve(arr1, arr2, 0, -1);
        sort(arr2.begin(), arr2.end());
        map<pair<int, int>,int>dp;
        int ans = solveTD(arr1, arr2, -1, 0, dp);
        return ans == INF ? -1 : ans;
        
    }
};
