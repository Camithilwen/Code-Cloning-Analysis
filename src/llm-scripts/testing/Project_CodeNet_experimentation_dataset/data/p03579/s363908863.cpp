#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string.h>
#include <set>

using namespace std;

#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl

template<class T> void printvec(const vector<T>& v) {
  for (auto x : v) { cout << x << " "; }
  cout << endl;
}
template<class T> void printtree(const vector< vector<T> >& tree) {
  for (long long i = 0; i < tree.size(); ++i) {
    cout << i + 1 << ": "; printvec(tree[i]);
  }
}
template<class T, class U> void printmap(const map<T, U>& mp) {
  for (auto x : mp) { cout << x.first << "=>" << x.second << endl; }
}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

#define rep(i, n) for(ll i = 0; i < n; ++i)
#define all(s) s.begin(), s.end()
#define fr first
#define sc second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> triple;
typedef double D;

const ll INF = 1e9;
const ll MOD = 1000000007;  // 1e9 + 7

vector<vector<ll>> g;
vector<ll> dp; // -1 .. no paint, 0 .. red, 1 .. blue

// c .. 0 or 1
bool dfs(int v, int c) {
  if (dp[v] >= 0) {
    return dp[v] == c;
  }
  // Here, dp[v] == -1
  dp[v] = c;
  int nc = c^1; // next color
  for (auto nv : g[v]) {
    if (!dfs(nv, nc)) { return false; }
  }
  return true;
}

int main(int argc, char** argv) {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  //cout << setprecision(10) << fixed;

  ll n, m;
  cin >> n >> m;
  g.resize(n);
  dp.assign(n, -1);
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    --a; --b; //0-indexed
    g[a].push_back(b);
    g[b].push_back(a);
  }

  if (dfs(0, 0)) { // g is bipartite grah
    ll red = 0;
    rep(i, n) {
      if (dp[i] == 0) { ++red; }
    }
    ll blue = n-red;
    cout << red*blue - m << endl;
  } else {
    cout << n*(n-1)/2 - m << endl;
  }
}
