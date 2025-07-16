#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <cstring>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  while(cin>>n>>k,n||k) {
    int cost[n][n]; FOR(i,0,n) FOR(j,0,n) cost[i][j] = 1e9;
    FOR(i,0,k) {
      int x; cin >> x;
      if(x == 0) {
        int d[n]; FOR(i,0,n) d[i] = 1e9;
        bool used[n]; CLR(used);
        // ??????????????????
        int a, b; cin >> a >> b;
        a--;b--;
        d[a] = 0;
        while(1) {
          int v = -1;
          for(int u = 0; u < n; u++) {
            if(!used[u] && (v == -1 || d[u] < d[v])) v = u;
          }
          if(v == -1) break;
          used[v] = true;
          for(int u = 0; u < n; u++) {
            d[u] = min(d[u], d[v] + cost[v][u]);
          }
        }
        if(d[b] >= 1e9) d[b] = -1;
        cout << d[b] << endl;
      } else {
        int c, d, e; cin >> c >> d >> e;
        c--;d--;
        cost[c][d] = min(cost[c][d], e);
        cost[d][c] = min(cost[d][c], e);
      }
    }
  }
  return 0;
}