// 539 leetcode  Minimum Time Difference
// Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 

// Example 1:

// Input: timePoints = ["23:59","00:00"]
// Output: 1
// Example 2:

// Input: timePoints = ["00:00","23:59","00:00"]
// Output: 0
 

// Constraints:

// 2 <= timePoints.length <= 2 * 104
// timePoints[i] is in the format "HH:MM".


class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        //step1: convert time string into minutes integer value
        vector<int> minutes;        

        for(int i=0; i<timePoints.size(); i++) {
            string curr = timePoints[i];        

            int hours = stoi( curr.substr(0,2) );    // 0 index se start karo aur 2 char utha le ao
            int min = stoi( curr.substr(3,2) );    // 3 index se start karo aur 2 char utha le ao
            int totalMinutes = hours*60 + min;
            minutes.push_back(totalMinutes);
        }

        //Step2: sort
        sort(minutes.begin(), minutes.end());

        //Step3: difference and calculate min diff
        int mini = INT_MAX;
        int n = minutes.size();

        for(int i=0; i<n-1; i++) {
            int diff = minutes[i+1] - minutes[i];
            mini = min(mini, diff);
        }

        //something missing - THIS IS THE GAME       //circular nature of array timePoints
        int lastDiff1 = (minutes[0] + 1440) - minutes[n-1];
        // int lastDiff2 = minutes[n-1] - minutes[0];
        // int lastDiff = min(lastDiff1, lastDiff2);
        mini = min(mini, lastDiff1);

        return mini;

    }
};
















