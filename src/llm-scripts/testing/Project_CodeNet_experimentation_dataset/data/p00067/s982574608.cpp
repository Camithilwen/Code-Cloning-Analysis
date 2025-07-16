#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <ctime>
#include <list>
#include <numeric>
#include <utility>
#include <ctime>
#define INF 1000000000
#define LINF 9000000000000000000
#define mod 1000000007

#define rep(i,n) for(int i=0;i<int(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back
#define mp make_pair
#define MOD(x) (x%(mod))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ddx[8]={-1,-1,0,1,1,1,0,-1};
int ddy[8]={0,1,1,1,0,-1,-1,-1};
bool debug=false;

/*---------------------------------------------------*/

char island[13][13];

void bfs(int x,int y){
  island[y][x]='0';
  queue<pi> que;
  que.push(mp(x,y));
  while(que.size()){
    pi d=que.front();que.pop();
    rep(i,4){
      int xx=d.first+dx[i],yy=d.second+dy[i];
      if(0<=xx&&xx<=12&&0<=yy&&yy<=12&&island[yy][xx]=='1'){
	que.push(mp(xx,yy));
	island[yy][xx]='0';
      }
    }
  }
}

int solve(){
  int ret=0;
  rep(i,12){
    rep(j,12){
      if(island[i][j]=='1'){
	ret++;
	bfs(j, i);
      }
    }
  }
  return ret;
}

int main(){
  char a;
  while(cin>>a){
    island[0][0]=a;
    // cout<<"in"<<endl;
    rep(i,12){
      rep(j,12){
	if(i==0&&j==0)continue;
	// cout<<i<<" "<<j<<endl;
	cin>>island[i][j];
      }
    }
    cout<<solve()<<endl;
  }
}


