#include<iostream>
#include<cstdio>
using namespace std;
int main(){
  int n;
  while(cin>>n,n){
    int matrix[11][11] = {0};
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
	cin >>matrix[i][j];
      }
    }
    int suma = 0;
    for(int i=0,sumc,sumr; i<n; i++){
      sumc = 0;
      sumr = 0;
      for(int j=0; j<n; j++){
	sumc+=matrix[i][j];
	sumr+=matrix[j][i];
      }
      suma+=sumc;
      matrix[i][n] = sumc;
      matrix[n][i] = sumr;
    }
    matrix[n][n] = suma;
    for(int i=0; i<=n; i++){
      for(int j=0; j<=n; j++){
	printf("%5d",matrix[i][j]);
      }
      cout <<endl;
    }
  }
  return 0;
}