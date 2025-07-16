#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cstring>
#include<string>

#define f first
#define s second
#define mp make_pair

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

typedef unsigned int uint;
typedef long long ll;

int main(){
  int n,m;
  while(scanf("%d%d",&n,&m), n+m){
    int time[100][100] = {{0}};
    int cost[100][100] = {{0}};
    REP(i,n){
      int a,b,c,d;
      scanf("%d%d%d%d",&a,&b,&c,&d);
      a--; b--;
      cost[a][b] = cost[b][a] = c;
      time[a][b] = time[b][a] = d;
    }
    int k;
    scanf("%d",&k);
    while(k --> 0){
      int p,q,type;
      int (*load)[100];
      scanf("%d%d%d",&p,&q,&type);
      if(type == 0) load = cost;
      else load = time;

      p--; q--;
      int memo[100];
      memset(memo, -1, sizeof(memo));
      priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > qq;
      qq.push(mp(0, p));
      while(qq.size()){
	int c = qq.top().f;
	int pos = qq.top().s;
	qq.pop();
	if(pos == q){
	  printf("%d\n",c);
	  break;
	}
	if(memo[pos] != -1)
	  continue;
	memo[pos] = c;
	REP(i,m){
	  if(memo[i] == -1 && load[pos][i] != 0)
	    qq.push(mp(c+load[pos][i], i));
	}
      }
    }
  }
  return 0;
}