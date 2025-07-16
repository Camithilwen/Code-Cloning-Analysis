#include <bits/stdc++.h>
using namespace std;
#define rep2(i, m, n) for(int i=int(m); i<int(n); ++i)
#define rep(i, n) rep2(i, 0, n)
using ll = long long;
using V = vector<int>;

char s[1000000];
ll t[3][1000001];

int main() {
  int n, q;
  scanf("%d%s%d", &n, s, &q);

  V D, C;
  rep(i, n) {
    rep(j, 3) t[j][i+1] = t[j][i];
    switch(s[i]){
      case 'D':
        ++t[0][i+1];
        D.push_back(i+1);
        break;
      case 'M':
        ++t[1][i+1];
        break;
      case 'C':
        ++t[2][i+1];
        C.push_back(i);
        break;
    }
  }

  ll suma = 0, sumc = 0;
  for (auto &a : D) suma += t[1][a] * t[2][a];
  for (auto &c : C) sumc += t[1][c] * t[0][c];

  rep(_, q) {
    int k; 
    scanf("%d", &k);
    ll ans = suma + sumc;
    for (auto &a : D) ans -= t[1][a] * t[2][min(a+k-1, n)];
    for (auto &c : C) ans -= t[1][c] * t[0][max(c-k+1, 0)];
    printf("%lld\n", ans);
  }
  return 0;
}
