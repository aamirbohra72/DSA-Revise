// 994. Rotting Oranges

// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

// Example 1:


// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4

// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// grid[i][j] is 0, 1, or 2.


// Apply bfs because it is level order traversal , to find time of rotten oranges , return max time, 

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<pair<int,int> , int > > q;
        vector<vector<int>> arr = grid;   //copy grid
        int count = 0;
        int ansTime = 0;
        //insert all rotten oranges in queue
        for(int row=0; row<grid.size(); row++) {
            for(int col=0; col<grid[row].size(); col++ ) {
                if(grid[row][col] ==2) {
                    //rotten orange found
                    pair<int,int> coordinate = make_pair(row, col);
                    q.push({coordinate,0});   //time = 0;
                }
            }
        }

        while(!q.empty()) {
            pair<pair<int,int> , int > fNode = q.front();
            q.pop();
            int x = fNode.first.first;
            int y = fNode.first.second;
            int time = fNode.second;

            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i=0; i<4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX >=0 && newX < arr.size() && newY >=0 && newY < arr[0].size() &&
                 arr[newX][newY] == 1) {
                     pair<int,int> newCoordinates = make_pair(newX, newY);
                     ansTime = max(ansTime, time+1);
                     q.push({newCoordinates, time + 1});
                     //mark rotten
                     arr[newX][newY] = 2;            // not use double operator
                 }
            }


        }

        //chec for fresh orange
        for(int i=0;i<arr.size(); i++) {
            for(int j=0;j<arr[0].size();j++) {
                if(arr[i][j] == 1) {
                    return -1;
                }
            }
        }
       return ansTime;

    }
};