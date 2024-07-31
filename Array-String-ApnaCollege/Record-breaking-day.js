#include<iostream>
#include<limits.h>
using namespace std;

// find out how many record breaking days are there in the given array
//check if the current element is greater than the previous element and the next element then only it is record breaking day


int main(){
  int n;
  cin>>n;
  int a[n+1]; // n+1 because we check for 0th index
   a[n] = -1;   // take previous value as -1 in start
  
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
// clearly mention least value as 2
  if(n==1){
    cout<<"1"<<endl;
    return 0;
  }
  int mx = -1;
  int ans =0;
  for(int i=0;i<n;i++){
    if(a[i]>mx && a[i]>a[i+1]){
      ans++;
    }
      mx = max(mx, a[i]);  //abhi tak ka maximum value since zero index se check karo
    
    
  }
  cout<<ans<<endl;

}



// ------------------------------------------------------
// 8
// 1 2 0 7 2 0 2 2
//  ans = 2  // 2 and 7 is the record breaking day


