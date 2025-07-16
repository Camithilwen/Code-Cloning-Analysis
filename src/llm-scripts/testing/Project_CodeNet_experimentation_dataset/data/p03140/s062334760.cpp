#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstring>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <regex>
#include <vector>

#define fix(n)          cout<<fixed<<setprecision(n)
#define rep(i,n)        for (int i = 0; i < (n); ++i)
#define sort(a)         sort((a).begin(), (a).end())
#define uniq(a)         SORT(a);(a).erase(unique((a).begin(), (a).end()), (a).end())
#define reverse(a)      reverse((a).begin(), (a).end())
#define ctos(c)         string(1, (c))
#define out(d)          cout << (d)
#define outl(d)         std::cout<<(d)<<"\n"
#define YES(n)          cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n)          cout << ((n) ? "Yes" : "No"  ) << endl
#define ceil(x, y)      ((x + y - 1) / (y))
#define debug(x)        cerr << #x << ": " << (x) << '\n'
#define debug2(x, y)    cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << '\n'
#define debug3(x, y, z) cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << ", " << #z << ": " << (z) << '\n'
#define dbg(v)          for (size_t _ = 0; _ < v.size(); ++_){ cerr << #v << "[" << _ << "] : " << v[_] << '\n'; }

using namespace std;
using ll = long long;
using P = pair<ll,ll>;

const ll MOD = 1000000007; // 10^9 + 7

void solve() {
  int n; cin >> n;
  string a, b, c; cin >> a >> b >> c;
  int ans = 0;
  rep(i, n) {
    set<char> s;
    s.insert(a[i]);s.insert(b[i]);s.insert(c[i]);
    if (s.size() == 3) ans += 2;
    else if (s.size() == 2) ans += 1;
  }
  outl(ans);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
