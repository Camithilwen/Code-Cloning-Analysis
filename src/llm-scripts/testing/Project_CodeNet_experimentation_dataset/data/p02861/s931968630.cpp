#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  vector<int> perm(n);
  rep(i, n) perm[i] = i;

  double sum_d = 0;
  int k = 0;
  do {
    ++k;
    rep(i, n-1) sum_d += sqrt(pow(x[perm[i+1]] - x[perm[i]], 2) + pow(y[perm[i+1]] - y[perm[i]], 2));
  } while (next_permutation(perm.begin(), perm.end()));
  double ave_d = sum_d / k;
  printf("%.7f\n", ave_d);
  return 0;
}