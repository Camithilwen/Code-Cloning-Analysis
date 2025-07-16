#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,a,b,x=0,count=0;
  while(1){
    cin >> n;
    if(n == 0) break;
    cin >> m;
    int data[n][n];
    int str[501]={0};
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	data[i][j]=0;
      }
    }
    for(int i=0;i<m;i++){
      cin >> a >> b;
      data[a-1][b-1]++;
      data[b-1][a-1]++;
      if( a == 1 ){
	str[x]=b-1;
	x++;
      } else if( b == 1){
	str[x]=a-1;
	x++;
      }
    }
    for(int i=0;i<x;i++){
      for(int j=1;j<n;j++){
	if(data[str[i]][j] != 0 && data[0][j] == 0){
	  data[0][j]++;
	}
      }
    }
    for(int i=1;i<n;i++){
      if( data[0][i] != 0){
      	count++;
      }
    }
    cout << count << endl;
    count=0;
    x=0;
  }
  return 0;
}