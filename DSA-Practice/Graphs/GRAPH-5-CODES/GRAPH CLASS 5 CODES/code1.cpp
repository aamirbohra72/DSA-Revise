



// No of provinces count

// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

 

// Example 1:


// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2
// Example 2:


// Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
// Output: 3
 

// Constraints:

// 1 <= n <= 200
// n == isConnected.length
// n == isConnected[i].length
// isConnected[i][j] is 1 or 0.
// isConnected[i][i] == 1
// isConnected[i][j] == isConnected[j][i]



class Solution {
    private:
    void dfs(unordered_map<int,bool>& vis, int src, vector<vector<int>>& isConnected) {
        //cout << "received a call for src: " << src << endl;
        vis[src] = true;
        //row -> src
        //col -> we will write a loop
        int size = isConnected[src].size();
        for(int col=0; col<size; col++) {
            if(src != col && isConnected[src][col] == 1) {
                //col is a nbr
                if(!vis[col] ) {
                    dfs(vis,col, isConnected);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,bool> visited;
        int count = 0;
        int n = isConnected.size();
        //i represents nodes here , run loop taking index of i and check if it is visited or not , if not visited then call dfs, 
        
        for(int i=0; i< n; i++)  {
            if(!visited[i]) {
                //cout << "calling for src: "<< i << endl;
                dfs(visited, i, isConnected);
                count++;
            }
        }
        return count;
    }
};