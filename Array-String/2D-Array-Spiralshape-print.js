#include<iostream>
#include<limits.h>
using namespace std;


int main(){
  int n,m;
  cin>> n >>m;
  int a[n][m];
  for(int i=0;i<n;i++){
    for(int j=0;j<m; j++){
      cin>>a[i][j];
    }
  }
 
int row_start=0, row_end=n-1, col_start=0, col_end=m-1;

while(row_start<=row_end && col_start<=col_end){
  //row_start
  for(int col=col_start;col<=col_end;col++){
    cout<<a[row_start][col]<<" ";
    
  }
  row_start++;

  //col_end
  for(int row=row_start;row<=row_end;row++){
    cout<<a[row][col_end]<<" ";
  }
  col_end--;

  //row_end
  for(int col=col_end;col>=col_start;col--){
    cout<<a[row_end][col]<<" ";
  }
  row_end--;

  //col_start
  for(int row=row_end;row>=row_start;row--){
    cout<<a[row][col_start]<<" ";
  }
  col_start++;
  
    }
  // cout<<a[i][j]<<endl;
return 0;

}

// --------------------------------------------------------------
// 5 6
// 1 5 7 9 10 11
// 6 10 12 13 20 21
// 9 25 29 30 32 41 
// 15 55 59 63 68 70 
// 40 70 79 81 95 105
// ans= 