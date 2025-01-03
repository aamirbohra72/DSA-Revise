// 1631. Path With Minimum Effort
// Medium
// Topics
// Companies
// Hint
// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

// Example 1:



// Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
// Output: 2
// Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
// This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
// Example 2:



// Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
// Output: 1
// Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
// Example 3:


// Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
// Output: 0
// Explanation: This route does not require any effort.
 

// Constraints:

// rows == heights.length
// columns == heights[i].length
// 1 <= rows, columns <= 100
// 1 <= heights[i][j] <= 106






class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > pq;
        vector<vector<int> > dist(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        pq.push({0, {0,0}});
        dist[0][0] = 0;

        while(!pq.empty()) {
            auto fNode = pq.top();
            pq.pop();
            int frontNodeDifference = fNode.first;
            int x = fNode.second.first;
            int y = fNode.second.second;

            //check ans tak toh nahi pahuch agye
            if(x == heights.size() - 1 && y == heights[0].size() - 1) {
                return dist[x][y];
            }

            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i=0; i<4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX >=0 && newY >=0 && newX <heights.size() && newY < heights[0].size()) {
                    int currDifference = abs(heights[x][y] - heights[newX][newY]);
                    int newMax = max(frontNodeDifference, currDifference);
                    if(newMax < dist[newX][newY]) {
                        dist[newX][newY] = newMax;
                        pq.push({newMax, {newX, newY}});
                    }
                }
            }
        }
        return 0;
    }
};