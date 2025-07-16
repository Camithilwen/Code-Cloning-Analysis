#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

vector<int> mp(vector<int> s) {
  int n = s.size();
  vector<int> ret(n + 1);
  ret[0] = -1;
  int j = -1;
  rep(i, n) {
    while (j >= 0 && s[i] != s[j]) j = ret[j];
    ret[i + 1] = ++j;
  }
  return ret;
}

vector<int> kmp(vector<int> str, vector<int> word) {
  vector<int> table = mp(word), ret;
  int m = 0, i = 0, n = str.size();
  while (m + i < n) {
    if (word[i] == str[m + i]) {
      if (++i == (int)(word.size())) {
        ret.push_back(m);
        m = m + i - table[i];
        i = table[i];
      }
    }
    else {
      m = m + i - table[i];
      if (i > 0) i = table[i];
    }
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  vector<int> c(n * 2), d(n);
  rep(i, n) {
    c[i] = a[i] ^ a[(i + 1) % n];
    c[i + n] = c[i];
  }
  rep(i, n) d[i] = b[i] ^ b[(i + 1) % n];

  vector<int> res = kmp(c, d);
  rep(i, res.size()) {
    int k = res[i];
    if (k >= n) break;
    int x = a[k] ^ b[0];
    cout << k << " " << x << endl;
  }


  
  return 0;
}