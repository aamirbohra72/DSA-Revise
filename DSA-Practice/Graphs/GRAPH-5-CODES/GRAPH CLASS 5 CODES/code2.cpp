// 200 leetcode , No of islands count 
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.


class Solution {
    private: 
    void bfs(map< pair<int,int> , bool >& visited, int row, int col, vector<vector<char>>& grid) {
        queue<pair<int,int> > q;
        //initial steps
        q.push({row,col});
        visited[{row,col}] = true;

        while(!q.empty()) {
            pair<int,int> fNode = q.front();
            q.pop();
            int x = fNode.first;
            int y = fNode.second;

            //i can move in 4 directions  left , down, right, up
            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i=0; i<4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if( newX >=0 && newX < grid.size() && newY>=0 && newY < grid[0].size() &&
                    !visited[{newX, newY}] && grid[newX][newY] == '1') {
                        
                        q.push({newX, newY});
                        visited[{newX, newY}] = true;
                }

            } 
    }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        map< pair<int,int>, bool > visited;
        int count = 0;

        for(int row=0; row<grid.size(); row++) {
            int n = grid[row].size();
            for(int col=0; col<n; col++) {
                if(!visited[{row,col}] && grid[row][col] == '1') {
                    bfs(visited, row, col,grid);
                    count++;
                }
            }
        }
        return count;
    }
};