#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;


int main() {
  string s;
  cin >> s;

  vector<ll> cnt(26, 0);
  ll n = s.size();
  ll res = n * (n - 1) / 2;
  rep(i,n) cnt[s[i] - 'a']++;
  rep(i,26) res -= cnt[i] * (cnt[i] - 1) / 2;
  cout << res + 1 << endl;
  return 0;
} 