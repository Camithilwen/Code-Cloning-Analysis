#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;

ll a[MAX_N];
ll b[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld %lld", &(a[i]), &(b[i]));
  }

  vector<pair<ll, int>> sum_index;

  for (int i = 0; i < n; ++i) {
    sum_index.emplace_back(a[i] + b[i], i);
  }

  sort(sum_index.begin(), sum_index.end(), greater<pair<ll, int>>());

  ll ans = 0LL;

  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      ans += a[sum_index[i].second];
    } else {
      ans -= b[sum_index[i].second];
    }
  }

  printf("%lld\n", ans);

  return 0;
}
