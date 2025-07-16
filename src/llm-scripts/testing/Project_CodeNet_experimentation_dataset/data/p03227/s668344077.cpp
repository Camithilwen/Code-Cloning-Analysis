#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define fin(ans) cout << (ans) << endl;
#define blank(ans) cout << (ans) << " ";
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef long long lli;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;

typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vpll;
typedef vector<pair<ll, str>> vpls;
typedef vector<tuple<str, ll, ll>> vtsl;
typedef vector<vector<ll>> vvll;
typedef vector<vector<char>> vvc;
typedef vector<vector<str>> vvs;

const ld PI = acos(-1.0);
const ll MAX = 9000000000000000000;
const ll MIN = -9000000000000000000;
const ld DMAX = 4500;
const ld DMIN = -4500;
const ll MOD = 1000000007;

//実行部
void Main()
{
  str s; cin >>s;
  if(s.size()==3) reverse(all(s));
  fin(s)
  return;
}

//前処理
int main()
{
  //ios::sync_with_stdio(false);
  //cin.tie(0);
  cout << fixed << setprecision(20); //高精度少数表示
  Main();
  return 0;
}
