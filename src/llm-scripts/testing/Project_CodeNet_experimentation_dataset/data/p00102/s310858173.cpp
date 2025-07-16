#include <iostream>
#include <cstring>
using namespace std;

int main(){
  int n;

  while(cin>>n,n){
    int t[n+1][n+1];
    memset(t,0,sizeof(t));
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cin>>t[i][j];
        t[i][n] += t[i][j];
        t[n][j] += t[i][j];
        t[n][n] += t[i][j];
      }
    }

    for(int i=0;i<=n;i++){
      for(int j=0;j<=n;j++){
        printf("%5d",t[i][j]);
      }
      printf("\n");
    }
  }
}