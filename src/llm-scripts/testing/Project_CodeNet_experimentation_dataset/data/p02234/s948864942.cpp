#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
#define MAX 100

int main(){
  int n,dammy;
  cin>>n;
  int p[MAX+1];
  cin>>p[0];
  for(int i=0;i<n-1;i++){
    cin>>p[i+1];
    cin>>dammy;
  }
  cin>>p[n];
  int C[MAX+1][MAX+1];
  for(int i=1;i<=n;i++) C[i][i]=0;
  for(int h=2;h<=n;h++){
    for(int s=1;s<=n-h+1;s++){
      int e=s+h-1;
      C[s][e]=C[s][s]+C[s+1][e]+p[s-1]*p[s]*p[e];
      for(int j=s+1;j<e;j++){
        C[s][e]=min(C[s][e],C[s][j]+C[j+1][e]+p[s-1]*p[j]*p[e]);
      }
    }
  }
  cout<<C[1][n]<<endl;
}

