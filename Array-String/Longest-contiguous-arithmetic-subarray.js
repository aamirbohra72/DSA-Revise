#include<iostream>
#include<limits.h>
using namespace std;
// Longest arithematic subarray
// a[j] - a[j-1]  = pd 
// ans = 2   update current ans to 2 , streak break ho gaye
// previous common difference


int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int ans = 2;
  int curr = 2;
  int pd = a[1] - a[0];
  int j=2;

  while(j<n){
    if(pd == a[j] - a[j-1]){
      curr++;
    }
    else{
      pd = a[j] - a[j-1];
      curr = 2;    // reset 
    }
    ans = max(curr, ans);
  j++;
  }
  cout<<ans<<endl;
  
  


}
//  -------------------Longest contiguous arithematic subarray ------------

// 7
// 10 7 4 6 8 10 11
//   ans = 4