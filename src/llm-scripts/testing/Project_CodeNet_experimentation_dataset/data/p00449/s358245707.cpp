#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cstring>
#include<string>
#include<sstream>

#define f first
#define s second
#define mp make_pair

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

typedef unsigned int uint;
typedef long long ll;

int sb[10][10000];

#define MAX (50000000)

int main(){
  int n,k;
  while(scanf("%d%d",&n,&k), n+k){
    int dist[n][n];
    REP(i,n) REP(j,n) dist[i][j] = MAX;
    REP(i,n) dist[i][i] = 0;
    while(k --> 0){
      int s; scanf("%d",&s);
      if(s == 0){
        int a,b;
        scanf("%d%d",&a,&b); a--; b--;
        if(dist[a][b] == MAX) puts("-1");
        else printf("%d\n",dist[a][b]);
      }else{
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c); a--; b--;
        if(dist[a][b] < c) continue;
        dist[a][b] = dist[b][a] = c;
        REP(i,n){
          dist[a][i] = dist[i][a] = min(dist[a][i], dist[a][b] + dist[b][i]);
          dist[b][i] = dist[i][b] = min(dist[b][i], dist[b][a] + dist[a][i]);
        }
        REP(i,n) REP(j,n){
          dist[i][j] = min(dist[i][j], dist[i][a] + dist[a][j]);
          dist[i][j] = min(dist[i][j], dist[i][b] + dist[b][j]);
        }
      }
    }
  }
  return 0;
}