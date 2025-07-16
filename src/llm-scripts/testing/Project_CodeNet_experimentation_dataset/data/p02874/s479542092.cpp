//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FIO ios_base::sync_with_stdio(false); cin.tie(0);
#define trav(x,a) for (auto& x: a)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define mem(a,v) memset((a), (v), sizeof (a))
#define endl "\n"
#define case(t) cout << "Case #" << (t) << ": "
#define reada(a, n) for (int _i = 0; _i < (n); _i++) read(a[_i])
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vii vector<pii>
#define vll vector<pll>
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef cc_hash_table<int,int,hash<int>> ht;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
const double pi = acos(-1);
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int N = 1e6 + 5;
const double eps = 1e-9;

template<class T> void read(T& x) { cin >> x; }
template<class X, class Y> void read(pair<X,Y>& a) { read(a.first), read(a.second); }
template<class T> void read(vector<T>& x) { trav(y, x) read(y); }
template<class T, class... O> void read(T& x, O&... y) { read(x), read(y...); }

string to_string(const char& x) { return string(1,x); }
string to_string(const char*& x) { return (string)x; }
string to_string(const string& x) { return x; }
template<class T, class U> string to_string(const pair<T,U>& x) { return to_string(x.first) + " " + to_string(x.second); }
template<class T> string to_string(const vector<T>& x) { string ret = ""; bool f = 0; trav(y, x) ret += (!f ? "" : " ") + to_string(y), f = 1; return ret; }
void print() { cout << endl; }
template<class T> void pr(const T& x) { cout << to_string(x); }
template<class T, class... O> void print(const T& x, const O&... y) { pr(x); if (sizeof...(y)) pr(" "); print(y...); }

int main() {
  FIO
  int n; read(n);
  vector<pair<int,int>> a(n); read(a);
  sort(all(a), [](pii l, pii r) { return (l.first != r.first) ? l.first < r.first : l.second < r.second; });
  vector<pair<int,int>> b;
  for (auto x: a) {
    while (sz(b) && b.back().first <= x.first && x.second <= b.back().second)
      b.pop_back();
    b.push_back(x);
  }
  int ans = 0;
  for (int i = 0; i+1 < sz(b); i++)
    ans = max(ans, max(0, b[0].second - b[i].first + 1) + max(0, b[i+1].second - b.back().first + 1));
  sort(all(a), [](pii l, pii r) { return l.second - l.first == r.second - r.first ? l.first < r.first : l.second - l.first > r.second - r.first; });
  int i = 0;
  for (; i+1 < n && a[0] == a[i]; i++);
  int val = a[0].second - a[0].first + 1;
  int lo = 0, hi = inf;
  for (; i < n; i++)
    lo = max(lo, a[i].first), hi = min(hi, a[i].second);
  val += max(0, hi - lo + 1);
  sort(all(a), [](pii l, pii r) { return l.second - l.first == r.second - r.first ? l.first > r.first : l.second - l.first > r.second - r.first; });
  i = 0;
  for (; i+1 < n && a[0] == a[i]; i++);
  lo = 0, hi = inf;
  for (; i < n; i++)
    lo = max(lo, a[i].first), hi = min(hi, a[i].second);
  val = max(val, a[0].second - a[0].first + 1 + max(0, hi - lo + 1));
  print(max(val, ans));
  return 0;
}
