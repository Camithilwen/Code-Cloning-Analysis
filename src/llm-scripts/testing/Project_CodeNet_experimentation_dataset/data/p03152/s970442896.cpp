#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef vector<int> vi;
const ll M = 1e9 + 7;

int main(void){
  int n, m; bool ok = true;
  scanf("%d %d", &n, &m);
  vi as(n), bs(m), cs(n * m, 0); vector<bool> seen(n * m, false);
  rep(i, n) {scanf("%d", &as[i]); as[i]--; if (seen[as[i]]) ok = false; seen[as[i]] = true;}
  fill(all(seen), false);
  rep(i, m) {scanf("%d", &bs[i]); bs[i]--; if (seen[bs[i]]) ok = false; seen[bs[i]] = true;}
  if (!ok){printf("%d\n", 0); return 0;}

  sort(all(as)); sort(all(bs));
  ll ans = 1;
  rep(i, n) rep(j, m) if (as[i] == bs[j]) cs[as[i]] = 1;
  for (int a: as) if (!cs[a]) cs[a] = m - (lower_bound(all(bs), a) - bs.begin());
  for (int b: bs) if (!cs[b]) cs[b] = n - (lower_bound(all(as), b) - as.begin());
  for (int x = n * m - 1; x >= 0; x--){
    if (!cs[x]){
      cs[x] = m - (lower_bound(all(bs), x) - bs.begin());
      cs[x] *= n - (lower_bound(all(as), x) - as.begin());
      cs[x] -= n * m - x - 1;
    }
    (ans *= cs[x]) %= M;
  }

  printf("%lld\n", ans);

  return 0;
}
