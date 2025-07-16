// clang-format off
#include <bits/stdc++.h>
#define int long long
#define main signed main()
// #define main int main()
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prec(n) fixed << setprecision(n)
#define stlice(from, to) substr(from, (to) - (from) + 1)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vpii> vvpii;
const int INF = sizeof(int) == sizeof(long long) ? 1000000000000000000LL : 1000000000;
const int MOD = 1000000007;
const double PI = acos(-1);
template<typename A, typename B> bool cmin(A &a, const B &b) { return a > b ? (a = b, true) : false; }
template<typename A, typename B> bool cmax(A &a, const B &b) { return a < b ? (a = b, true) : false; }
bool odd(const int &n) { return n & 1; }
bool even(const int &n) { return !odd(n); }
template<typename V> typename V::value_type sum(const V &v) { return accumulate(all(v), 0); }
void solve();
main { solve(); return 0; }
// clang-format on

bool f(string s) {
  vs t;
  t.pb("the");
  t.pb("the.");
  t.pb("this");
  t.pb("this.");
  t.pb("that");
  t.pb("that.");
  stringstream ss;
  ss << s;
  string x;
  while (ss >> x) {
    if (find(all(t), x) != t.end()) return true;
  }
  return false;
}

void nextS(string &s) {
  rep(i, s.size()) {
    if ('a' <= s[i] && s[i] <= 'z') {
      s[i] = (s[i] - 'a' + 1) % 26 + 'a';
    }
  }
}

void solve() {
  string s;
  while (getline(cin, s)) {
    do {
      if (f(s)) {
        cout << s << endl;
        break;
      }
    } while (nextS(s), 1);
  }
}