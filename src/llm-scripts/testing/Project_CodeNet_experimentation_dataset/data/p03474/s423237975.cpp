#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}

int a, b;
string s;

int main() {
#ifdef LOCAL
  freopen("c.txt", "r", stdin);
// freopen("main.txt", "w", stdout);
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#define dbg(...) 18
#endif
  bool ans = true;
  cin >> a >> b >> s;
  if (SZ(s) <= a)
    ans = false;
  else if (s[a] != '-')
    ans = false;
  dbg(ans);
  for (int i = 0; i < SZ(s) && ans; i++) {
    if (i == a) continue;
    ans = s[i] >= '0' && s[i] <= '9';
  }
  dbg(ans);
  ans = ans && (SZ(s) == (a + b + 1));
  if (ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}