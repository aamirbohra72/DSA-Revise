#include<iostream>
#include<limits.h>
using namespace std;




int main(){
  int n;
  cin>>n;
  int a[n];
  
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  const int N = 1e6 + 2;
  int idx[N];
  
  for(int i=0;i<N;i++){
    idx[i] = -1;
  }
  int minIdx = INT_MAX;
  
  for(int i=0;i<n;i++){
    if(idx[a[i]] != -1){
      minIdx = min(minIdx, idx[a[i]]);
    }else{
      idx[a[i]] = i;
    }
  }
  if(minIdx == INT_MAX){
    cout<<"-1"<<endl;
  }
  else{
    cout<<minIdx+1<<endl;
  }
  

  return 0;
}


// ------------------first Repeating element ----------------------------

7
1 5 3 4 3 5 6

0  1  2  3  4  5  6     // idx[i] = -1
-1 -1 -1 -1 -1 -1 -1    //if(idx[a[i]] ! = -1){minIdx = min(minIdx, idx[a[i]])}else{ a[i]  = i}
-1 0  -1  -1 -1 -1 -1
-1 0 -1  -1 -1  1 -1
-1 0  -1  2  -1  1  -1
-1 0  -1  2  3   1  -1
-1 

// ans = 2
