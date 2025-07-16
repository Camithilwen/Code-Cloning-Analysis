#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

ll m[100][100];

void show_table(ll I, ll J) {
  for (ll i = 0; i <= I; i++) {
    for (ll j = 0; j <= J; j++) {
      cout << m[i][j] << " ";
    }
    cout << "" << endl;
  }
  cout << "" << endl;
}

int main() {
  // std::cout << std::fixed << std::setprecision(10);
  ll H, W;
  scanf("%lld %lld", &H, &W);

  for (ll y = 0; y < H; y++) {
    for (ll x = 0; x < W; x++) {
      m[y][x] = -1;
    }
  }

  ll spaces = 0;

  for (ll y = 0; y < H; y++) {
    string s;
    cin >> s;

    for (ll x = 0; x < W; x++) {
      if (s[x] == '.') {
        m[y][x] = INF;
        spaces++;
      }
    }
  }

  queue<pll> q;
  q.push(make_pair(0, 0));
  m[0][0] = 0;

  for (;;) {
    if (q.empty()) {
      break;
    }
    auto pos = q.front();
    ll y = pos.first;
    ll x = pos.second;

    ll c = m[y][x];

    if (y >= 1 && m[y - 1][x] > c + 1) {
      m[y - 1][x] = c + 1;
      q.push(make_pair(y - 1, x));
    }
    if (y < H - 1 && m[y + 1][x] > c + 1) {
      m[y + 1][x] = c + 1;
      q.push(make_pair(y + 1, x));
    }
    if (x >= 1 && m[y][x - 1] > c + 1) {
      m[y][x - 1] = c + 1;
      q.push(make_pair(y, x - 1));
    }
    if (x < W - 1 && m[y][x + 1] > c + 1) {
      m[y][x + 1] = c + 1;
      q.push(make_pair(y, x + 1));
    }

    q.pop();
  }

  // show_table(3, 3);

  ll a = m[H - 1][W - 1];

  if (a == INF) {
    cout << -1 << endl;
    return 0;
  }
  // cout << "a:" << a << endl;

  ll ans = spaces - a - 1;

  cout << ans << endl;
}
