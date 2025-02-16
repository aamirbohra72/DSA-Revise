// 632. Smallest Range Covering Elements from K Lists
// Hard
// Topics
// Companies
// You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

// We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

// Example 1:

// Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
// Output: [20,24]
// Explanation: 
// List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
// List 2: [0, 9, 12, 20], 20 is in range [20,24].
// List 3: [5, 18, 22, 30], 22 is in range [20,24].
// Example 2:

// Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
// Output: [1,1]
 

// Constraints:

// nums.length == k
// 1 <= k <= 3500
// 1 <= nums[i].length <= 50
// -105 <= nums[i][j] <= 105
// nums[i] is sorted in non-decreasing order.


class node{
    public:
    int data;
    int row;
    int col;
    
    node(int d, int r, int c) {
        data = d;
        row = r;
        col = c;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;
    }
};
 
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        priority_queue<node*, vector<node*>, compare> minHeap;
        int k = nums.size();
        for(int i=0; i<k; i++) {
            int element = nums[i][0];
            maxi = max( maxi, element);
            mini = min(mini, element);
            minHeap.push(new node(element, i, 0));
        }

        int ansStart = mini;
        int ansEnd = maxi;


        while(!minHeap.empty()) {
            
            node* top = minHeap.top();
            int topelement = top->data;
            int topRow = top->row;
            int topCol = top->col;
            minHeap.pop();

            //mini updated
            mini = topelement;

            //check for answer
            int currRange = maxi-mini;
            int ansRange = ansEnd - ansStart;
            if(currRange < ansRange) {
                ansStart = mini;
                ansEnd = maxi;
            }

            //check for new element in the same list
            if(topCol + 1 < nums[topRow].size()) {
                maxi = max( maxi , nums[topRow][topCol+1]);
                node* newNode = new node(nums[topRow][topCol+1], topRow, topCol+1);
                minHeap.push(newNode);
            }
            else {
                //there is no element int the same array or list
                break;
            }
        }

        vector<int> ans ;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;




    }
};







