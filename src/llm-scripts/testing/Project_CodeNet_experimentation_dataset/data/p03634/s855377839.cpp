#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const double PI = 3.14159265358979;

struct Edge{ ll cost, to; };
void solve()
{
  ll n, a, b, c;
  cin >> n;
  vector< vector<Edge> > G(n, vector<Edge>());
  for(int i = 0; i < n - 1; ++i)
  {
    cin >> a >> b >> c;
    a--; b--;
    G[a].emplace_back(Edge{c, b});
    G[b].emplace_back(Edge{c, a});
  }

  ll q, k, x, y;
  cin >> q >> k;
  k--;

  const ll INF = 1LL << 60;
  vector<ll> d(n, INF);
  d[k] = 0;
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(0, k)); // P(cost, start)
  while (!que.empty())
  {
    P p = que.top();
    que.pop();
    ll node = p.second;
    if (d[node] < p.first) continue;
    for (const auto& edge : G[node])
    {
        if (d[edge.to] > d[node] + edge.cost)
        {
            d[edge.to] = d[node] + edge.cost;
            que.push(P(d[edge.to], edge.to));
        }
    }
  }

  for(int i = 0; i < q; ++i)
  {
    cin >> x >> y;
    x--; y--;
    cout << d[x] + d[y] << endl;
  }

}

int main()
{
  fastio;
  solve();

  return 0;
}