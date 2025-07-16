#include <bits/stdc++.h>
using namespace std;
//#include <boost/multiprecision/cpp_int.hpp>
//using multiInt = boost::multiprecision::cpp_int;

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename Q_temp>
using smaller_queue = priority_queue<Q_temp, vector<Q_temp>, greater<Q_temp>>;

const ll MOD = (ll)(1e9 + 7);
const int INF = (int)1e9;
const ll LINF = (ll)4e18;
const double PI = acos(-1.0);

#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)
#define rep(i, n) REP(i, 0, n)
#define MP make_pair
#define MT make_tuple
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl
#define possible(n) cout << ((n) ? "possible" : "impossible") << endl
#define Yay(n) cout << ((n) ? "Yay!" : ":(") << endl
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x) cerr << #x << ":" << x << endl;

vector<int> Dx = {0, 0, -1, 1, -1, 1, -1, 1, 0};
vector<int> Dy = {1, -1, 0, 0, -1, -1, 1, 1, 0};

int main()
{

  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(50) << setiosflags(ios::fixed);

  int n, m;
  cin >> n >> m;
  int a[100010], b[100010];
  vector<int> E[100010];
  int in_cnt[100010] = {};
  rep(i, n + m - 1)
  {
    cin >> a[i] >> b[i];
    E[a[i]].push_back(b[i]);
    in_cnt[b[i]]++;
  }
  int root;
  for (int i = 1; i <= n; ++i)
  {
    if (in_cnt[i] == 0)
    {
      root = i;
      break;
    }
  }

  queue<int> que;
  int d[100010];
  int check_cnt[100010] = {};
  d[root] = 0;
  que.push(root);
  while (!que.empty())
  {
    int q = que.front();
    que.pop();
    for (auto to : E[q])
    {
      d[to] = d[q] + 1;
      check_cnt[to]++;
      if (check_cnt[to] == in_cnt[to])
        que.push(to);
    }
  }

  int par[100010];
  for (int i = 1; i <= n; ++i)
    par[i] = -1;
  par[root] = 0;
  que.push(root);
  while (!que.empty())
  {
    int q = que.front();
    que.pop();
    for (auto to : E[q])
    {
      if (par[to] != -1)
        continue;
      if (d[to] == d[q] + 1)
      {
        par[to] = q;
        que.push(to);
      }
    }
  }

  for (int i = 1; i <= n; ++i)
    cout << par[i] << endl;
  return 0;
}
