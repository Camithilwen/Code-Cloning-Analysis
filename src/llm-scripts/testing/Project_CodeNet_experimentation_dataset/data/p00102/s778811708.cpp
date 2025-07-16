#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  
  cin >> n;
  
  while(n != 0){
    
    int a[12][12] ={};

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	cin >> a[i][j];
	a[i][n] += a[i][j];
	a[n][j] += a[i][j];
      }
      a[n][n] += a[i][n];
    }
    
    for(int i=0;i<=n;i++){
      for(int j=0;j<=n;j++){
	printf("%5d",a[i][j]);
      }
      printf("\n");
    }
    
    cin >> n;
  }

  return (0);
}