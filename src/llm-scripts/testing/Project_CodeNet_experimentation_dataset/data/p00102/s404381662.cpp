#include <iostream>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)

int n, m;
int t[13][13];
int main(){
  while(cin >> n, n){
    rep(i,13)rep(j,13)t[i][j]=0;
    rep(i,n)rep(j,n){
      cin >> m;
      t[i][j] = m;
      t[n][j] += m;
      t[i][n] += m;
      t[n][n] += m;
    }
    rep(i,n+1){
      rep(j,n+1){
	printf("%5d",t[i][j]);
      }
      cout << endl;
    }
  }
  return 0;
}