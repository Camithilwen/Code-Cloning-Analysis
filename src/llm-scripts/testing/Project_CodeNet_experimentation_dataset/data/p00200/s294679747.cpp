#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int road1[111][111];
  int road2[111][111];
  int n,m;
  int a,b,cost,time;
  int p,q,r;
  int x;
  while(1){
    for(int i=0;i<111;i++){
      for(int j=0;j<111;j++){
	road1[i][j]=road2[i][j]=111111111;
      }
    }
    cin >> n >> m;
    if(n==0 && m==0)break;
    for(int i=0;i<n;i++){
      cin >> a >> b >> cost >> time;
      road1[a][b]=road1[b][a]=cost;
      road2[a][b]=road2[b][a]=time;
    }

    for(int k=1;k<=m;k++){
      for(int i=1;i<=m;i++){
	for(int j=1;j<=m;j++){
	  if(road1[i][j]>road1[i][k]+road1[k][j]){
	    road1[i][j]=road1[i][k]+road1[k][j];
	  }
	  if(road2[i][j]>road2[i][k]+road2[k][j]){
	    road2[i][j]=road2[i][k]+road2[k][j];
	  }
	}
      }
    }
    
    cin >> x;
    for(int i=0;i<x;i++){
      cin >> p >> q >> r;
      cout << (r==0 ? road1[p][q] : road2[p][q]) << endl;
    }
  }
}