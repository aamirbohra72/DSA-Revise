//Huffman encoding u have to do , 3+2= 5, 5+4 = 9, 9+6=15  5+9+15=29 ans  take min and add using priority queue 

#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
  int arr[] = {4,3,2,6};
  int n = 4;

  priority_queue<int, vector<int>, greater<int> > pq;
  for(int i=0; i<n; i++) {
    pq.push(arr[i]);
  }
  int cost = 0;
  while(pq.size() != 1) {
    int first = pq.top();
    pq.pop();
    int second = pq.top();
    pq.pop();

    cost += first + second;
    int newLength = first + second;
    pq.push(newLength);

  }
  cout << "Cost is: " << cost << endl;
  return 0;
}