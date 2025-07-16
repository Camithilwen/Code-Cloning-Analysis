
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,n) for(i=a;i<n;i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef pair<int,int> pii;

int i,j;
int a[105][105];
int used[105][105];
int h,w;

void search(int y,int x,int c){
  if(x<0 || y<0 || y>=h || x>=w || a[y][x]!=c)return;
  if(used[y][x])return;
  used[y][x]++;
  int i;
  int dx[4]={-1,0,1,0};
  int dy[4]={0,-1,0,1};
  rep(i,4)
    search(y+dy[i],x+dx[i],c);
  return;
}

int main(void) {
  while(1){
    cin>>w>>h;
    if(h==0 && w==0)break;
    rep(i,h)rep(j,w)used[i][j]=0;
    int xs,ys,xg,yg,n;
    cin>>xs>>ys;
    xs--;ys--;
    cin>>xg>>yg;
    xg--;yg--;
    cin>>n;
    rep(i,n){
      int c,d,x,y;
      cin>>c>>d>>x>>y;
      x--;y--;
      int p[8]={0,0,0,0,1,1,1,1};
      int q[8]={0,1,2,3,0,1,2,3};
      if(d)
	rep(j,8)
	  a[y+q[j]][x+p[j]]=c;
      else
	rep(j,8)
	  a[y+p[j]][x+q[j]]=c;
    }  
    if(a[ys][xs]==0){
      cout<<"NG"<<endl;
      continue;
    } 
    search(ys,xs,a[ys][xs]);//dfs
    if(used[yg][xg])
      cout<<"OK"<<endl;
    else
      cout<<"NG"<<endl;
  }
  return 0;
}