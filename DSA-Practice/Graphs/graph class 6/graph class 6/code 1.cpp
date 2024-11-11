// 207 Course Schedule

// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

// Constraints:

// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= 5000
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// All the pairs prerequisites[i] are unique.


// Note //dependency graph = topological sort,  Directed Acyclic Graph (valid)  , cyclic graph(invalid), 
// check valid and invalid using length of list (top.length == n) , kahns algo (size of adj list)
class Solution { 
private:
  bool topoSortBfs(int n, unordered_map<int,list<int> >& adjList) {
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
      return true;
    }
    else {
      //invalid
      return false;
    }
    
  }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int> > adjList;
        //build adjacency list
        for(auto task: prerequisites) {
          int u = task[0];
          int v = task[1];
          adjList[v].push_back(u);
        }

        bool ans = topoSortBfs(numCourses, adjList);
        return ans;
    }
};