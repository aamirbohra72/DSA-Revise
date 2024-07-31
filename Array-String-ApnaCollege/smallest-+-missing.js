#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }

  const int N = 1e6+2;
  bool check[N];
  for(int i=0;i<N;i++){
    check[i]= false;
  }
  for(int i=0;i<n;i++){
    if(a[i]>=0){
      check[a[i]] = true;
    }
  }
  int ans = -1;
  for(int i=0;i<N;i++){
    if (check[i]==  false){
      ans = i;
      break;
      
    }
  }
  cout<<ans<<endl;
  return 0;
}


// -----------first smallest positive no is missing ----------------------
// 6
// 0 -9 1 3 -4 5
// 0 1 2 3 4 5 6
// F F F F F F    STEP = 1
// T F F F F F 
// T T F F F F 


// T T F T F T

// ANS = 2;  // FIND FIRST POSITIVE MISSING NO 

