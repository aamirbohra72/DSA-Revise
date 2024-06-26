#include<iostream>
#include<limits.h>
using namespace std;




int main(){
  int n,s;
  cin>>n>>s;
  int a[n];
  
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  

int i=0,j=0,st=-1,en=-1, sum=0;
  while(j<n && sum+a[j]<=s){
    sum += a[j];
    j++;
  }
  if(sum == s){
    cout<<i+1<<" "<<j<<endl;
    return 0;
  }

  while(j<n){
    sum += a[j];
    while(sum>s){
      sum -= a[i];
      i++;
    }
    if(sum == s){
      st = i+1;
      en = j+1;
      break;
    }
    j++;
  }
  cout<<st<<" "<<en<<endl;
  
}

// ------------------------------Contiguous SubArray Sum --------------------------------
// 1)Example
// 5 12 
// 1 2 3 7 5
// -> 2 3 7 <-
// ans = 2 4

// 2)
// 4 5 
// 1 2 3 8 
// ans = 2 3 

// 3)
// 6 8 
// 1 2 3 5 7 2 
// 3 4






