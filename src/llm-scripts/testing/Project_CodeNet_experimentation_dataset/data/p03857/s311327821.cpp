#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <queue>
using namespace std;

#define N 200002

int fdsu[N],sdsu[N];

vector<int> g[N];
bool isSorted[N];
int f(int *dsu,int x) {
  if(dsu[x]==x) {
    return x;
  }
  return dsu[x] = f(dsu,dsu[x]);
}
void merge(int *dsu,int x,int y,int bit=0) {
  x = f(dsu,x),y = f(dsu,y);
  if(x!=y) {
    if(g[x].size()>g[y].size()) {
      swap(x,y);
    }
    dsu[x] = y;
    if(bit) {
      while(!g[x].empty()) {
        g[y].push_back(g[x].back());
        g[x].pop_back();
      }
    }
  }
}
void solve() {
  int n,k,l;scanf("%d %d %d",&n,&k,&l);
  for(int i=n;i;--i) {
    fdsu[i] = i;sdsu[i] = i;
  }
  for(int i=k;i;--i) {
    int x,y;scanf("%d %d ",&x,&y);
    merge(fdsu,x,y);
  }
  for(int i=n;i;--i) {
    g[i].push_back(f(fdsu,i));
  }
  for(int i=l;i;--i) {
    int x,y;scanf("%d %d",&x,&y);
    merge(sdsu,x,y,1);
  }
  for(int i=1;i<=n;++i) {
    int id = f(sdsu,i);
    if(!isSorted[id]) {
      sort(g[id].begin(),g[id].end());
      isSorted[id] = true;
    }
    int x = f(fdsu,i);
    printf("%d ",
    int(lower_bound(g[id].begin(),g[id].end(),x+1) - lower_bound(g[id].begin(),g[id].end(),x))  );
  }
  putchar('\n');
}

int main() {
  //freopen("input.txt","r",stdin);
  solve();
  return 0;
}
