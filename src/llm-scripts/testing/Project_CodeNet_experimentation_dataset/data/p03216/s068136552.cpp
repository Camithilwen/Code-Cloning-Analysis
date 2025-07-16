#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr int INF = 2e9;
int main() {
  int n, q;
  string s;
  cin >> n >> s >> q;
  while (q--) {
    int k;
    cin >> k;
    ll a = 0, b = 0, c = 0;
    ll res = 0;
    for (int i = 0; i < n; i++) {
      if (i >= k) {
        if (s[i - k] == 'D') a--, c -= b;
        if (s[i - k] == 'M') b--;
      }
      if (s[i] == 'D') a++;
      if (s[i] == 'M') b++, c += a;
      if (s[i] == 'C') res += c;
    }
    cout << res << endl;
  }
  return 0; 
} 