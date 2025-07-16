#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
//#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#define INF 0x3f3f3f
typedef long long ll;
const int maxn = 1e3 + 5;
const ll mod = 1e9 + 7;
const double pi = acos(-1.0);
int n, m;
int dis[maxn][maxn];
std::vector<int> v[maxn];

void GetDistance(int u) {
  std::queue<int> q;
  q.push(u);
  dis[u][u] = 0;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
  
    for (int i=0; i < v[cur].size(); i++) {
      if (dis[u][cur] + 1 < dis[u][v[cur][i]]) {
        dis[u][v[cur][i]] = dis[u][cur] + 1;
        q.push(v[cur][i]);
      }
    }
  }
}

void FindPath(int s, int t, std::set<int> &S) {
  int pre[maxn];
  memset(pre, 0, sizeof(pre));
  S.insert(s);
  std::queue<int> q;
  q.push(s);
  pre[s] = s;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (cur == t) {
      int u = cur;
      while (pre[u] != s) {
        u = pre[u];
        S.insert(u);
      }
      return;
    }
    
    for (int i=0; i < v[cur].size(); i++) {
      if (!pre[v[cur][i]]) {
        pre[v[cur][i]] = cur;
        q.push(v[cur][i]);
      }
    } 
  }
}

int main(int argc, char **argv){
  std::cin >> n >> m;
  int x, y;
  for (int i=1; i <= m; i++) {
    std::cin >> x >> y;
    v[x].push_back(y);
  }

  memset(dis, INF, sizeof(dis));
  for (int i=1; i <= n; i++) {
    GetDistance(i);
  }
  
  int ans = n+2;
  int s = -1, t = -1;
  for (int i=1; i <= n; i++) {
    for (int j=i+1; j <= n; j++) {
      if (dis[i][j] + dis[j][i] < ans) {
        ans = dis[i][j] + dis[j][i];
        s = i;
        t = j;
      }
    }
  }
  
  // std::cout << s << " " << t << " " << ans << std::endl;
  if (s != -1 && t != -1) {
    std::cout << ans << std::endl;
    std::set<int> S;
    FindPath(s, t, S);
    FindPath(t, s, S);
    for (auto& it: S) {
       std::cout << it << std::endl;
    }
  } else {
    std::cout << "-1" << std::endl;
  }
  return 0;
}
