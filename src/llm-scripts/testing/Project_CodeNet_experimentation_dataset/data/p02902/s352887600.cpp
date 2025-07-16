#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <memory.h>

using namespace std;

#define N 1001
#define M 20
#define mod 998244353
vector<int> adj[N];

int vis[N],par[N];

int depth[N];
int anc[N][M];

int outSize = 100000;

vector<int> ret;

void dfs(int node) {
  vis[node] = 1;
  for(int i=0;i<adj[node].size();++i) {
    int ch = adj[node][i];
    if(vis[ch] ) {
      if(depth[node]<=depth[ch]) continue;
      int diff = depth[node] - depth[ch];
      int tmp = node;
      for(int j= 0;j<M;++j) {
        if(diff&(1<<j)) {
          tmp = anc[tmp][j];
        }
      }
      if(tmp!=ch || outSize <=diff) {
        continue;
      }
      tmp = node;
      ret.clear();
      outSize = diff;
      while(true) {
        ret.push_back(tmp);
        if(tmp==ch) break;
        tmp = par[tmp];
      }

    } else {
      depth[ch] = depth[node] + 1;
      anc[ch][0] = node;
      for(int j=1;j<M;++j) {
        anc[ch][j] = anc[anc[ch][j-1]][j-1];
      }
      par[ch] = node;
      dfs(ch);
    }
  }
}
void solve() {
  int n,m;scanf("%d %d",&n,&m);
  for(int i=0;i<m;++i) {
    int a,b;scanf("%d %d",&a,&b);
    adj[a].push_back(b);
  }

  for(int st=1;st<=n;++st) {
    memset(vis,0,sizeof(vis));
    depth[st] = 0;
    for(int j=0;j<M;++j) anc[st][j] = 0;
    dfs(st);
  }
  if(outSize==100000) {
    printf("-1\n");
  } else {
    printf("%d\n",ret.size());
    for(int i=0;i<ret.size();++i) {
      printf("%d\n", ret[i]);
    }
  }
}

int main() {
  //freopen("input.txt","r",stdin);
  solve();
  return 0;
}
