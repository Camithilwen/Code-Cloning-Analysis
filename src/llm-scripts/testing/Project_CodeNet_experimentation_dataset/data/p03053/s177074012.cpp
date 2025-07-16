#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define Rep(i, n) for(int i=0;i<n;++i)
#define rep(i, n) for(int i=1;i<=n;++i)
#define ll long long int
#define INF 1e9
#define LINF 1e18
#define MOD 1000000007
#define PI 3.14159265359
#define EPS 1e-10
#define All(a) (a).begin(), (a).end()

using namespace std;
using P = pair<ll, ll>;
 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

/**
 * Usage:
 * 
 * G[from].push_back(Edge(to, weight));
 * using Graph = vector<vector<Edge>>;
 * 
 */ 
struct Edge {
  int to;     
  ll weight; 
  Edge(int t, ll w) : to(t), weight(w) { }
};

/**
 * Usage:
 * 
 * chmin(old, new);
 * chmax(old, new);
 * 
 */ 
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template<typename T>
void printv(vector<T>& v) {
  if (v.size() == 0) {
    cout << "\n";
    return;
  }

  Rep(i, v.size()) {
    cout << v[i] << ((i + 1 < v.size()) ? ' ' : '\n');
  }
}



int H, W;
char maze[1100][1100];
int d[1100][1100];

int main () {
  cin >> H >> W;
  queue<P> que;
  Rep(i, H) {
    Rep(j, W) {
      cin >> maze[i][j];
      if (maze[i][j] == '#') que.emplace(i, j);
    }
  }

  int ans = 0;

  while (!que.empty()) {
    int n = que.size();

    queue<P> new_que;
    Rep(i, n) {
      P p = que.front(); que.pop();
      Rep(k, 4) {
        int new_y = p.first + dy[k];
        int new_x = p.second + dx[k];

        if (new_y >= 0 & new_y < H & new_x >= 0 & new_x < W) {
          if (maze[new_y][new_x] == '.') {
            new_que.emplace(new_y, new_x);
            //cout << new_y << new_x << "\n";
            maze[new_y][new_x] = '#';
          }
        }
      }
    }
    que = new_que;

    ++ans;
    //cout << ans << "\n";
  }

  cout << ans -1<< "\n";
}