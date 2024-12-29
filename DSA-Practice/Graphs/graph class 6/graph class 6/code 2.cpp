// 210 course schedule II

// 210. Course Schedule II
// Medium
// Topics
// Companies
// Hint
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
// Example 2:

// Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
// So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
// Example 3:

// Input: numCourses = 1, prerequisites = []
// Output: [0]
 

// Constraints:

// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= numCourses * (numCourses - 1)
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// ai != bi
// All the pairs [ai, bi] are distinct.



class Solution {
private:
  vector<int> topoSortBfs(int n, unordered_map<int,list<int> >& adjList) {
    vector<int> ans;
    queue<int> q;
    unordered_map<int, int> indegree;

    //indegree calculate
    for(auto i: adjList ) {
      int src = i.first;
      for(auto nbr:i.second) {
        indegree[nbr]++;
      }
    }

    //put all nodes inside queue, which has indegree=0
    for(int i=0; i<n; i++) {
      if(indegree[i] == 0) {
        q.push(i);
      }
    }

    //bfs logic
    while(!q.empty()) {
      int fNode = q.front();
      q.pop();

      ans.push_back(fNode);
      //or we can do count++

      for(auto nbr: adjList[fNode]) { 
        indegree[nbr]--;
        //check for zero again
        if(indegree[nbr] == 0) {
          q.push(nbr);
        } 
      }
      
    }

    if(ans.size() == n) {
      //valid topo sort
      return ans;
    }
    else {
      //invalid
      return {};
    }
    
  }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int> > adjList;
        //build adjacency list
        for(auto task: prerequisites) {
          int u = task[0];
          int v = task[1];
          adjList[v].push_back(u);
        }

        vector<int> ans = topoSortBfs(numCourses, adjList);
        return ans;
    }
};