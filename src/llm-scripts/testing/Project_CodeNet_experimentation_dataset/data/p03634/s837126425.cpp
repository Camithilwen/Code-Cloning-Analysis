#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
#include<queue>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;
const int MOD = 1000000007;

#define rep(i,n) for (int i = 0; i < (n); ++i)

vector<vector<pair<int, ll>>> eda(100000 + 5); // pair には num, dist
vector<ll> dist(100000 + 5);

void makeCost(int n, int k)
{
  queue<pair<pair<int,ll>, int>> q; // pair には ((num, dist) from)
  dist[k] = 0;
  for (auto a : eda[k]) {
    q.push(make_pair(a, k));
  }

  while (!q.empty()) {
    auto now = q.front();
    q.pop();
    int number = now.first.first;
    int from = now.second;
    ll distance = now.first.second;
    dist[number] = dist[from] + distance;
    for (auto tmp : eda[number]) {
      if (tmp.first == from) continue;
      q.push(make_pair(tmp, number));
    }
  }
}

int main()
{
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    eda[a].push_back(make_pair(b, c));
    eda[b].push_back(make_pair(a, c));
  }

  int q, k;
  cin >> q >> k;

  makeCost(n, k);

  rep (i, q) {
    int x, y;
    cin >> x >> y;
    cout << dist[x] + dist[y] << endl;
  }
}

