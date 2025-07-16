#include <bits/stdc++.h>
#define P pair<int, int>

using namespace std;
const int INF=1e5;

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};


int main(){
  int h,w,a[1009][1009];
  string s[1009];
  cin >> h >> w;
  memset(a, -1, sizeof(a));
  for(int i=0;i<h;i++)cin >> s[i];
  queue<P> q;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]=='#'){
        a[i][j]=0;
        q.push(P(i,j));
      }
    }
  }
  int mx=0;
  while(!q.empty()){
    P p=q.front();q.pop();
    int ci=p.first;
    int cj=p.second;
    for(int i=0;i<4;i++){
      int ni=ci+dy[i];
      int nj=cj+dx[i];
      if(!(0<=ni&&ni<h&&0<=nj&&nj<w))continue;
      if(a[ni][nj]==-1){
        a[ni][nj]=a[ci][cj]+1;
        mx = max(mx, a[ni][nj]);
        q.push(P(ni, nj));
      }
    }
  }
  cout << mx << endl;
}

