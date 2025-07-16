#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  rep(i, n) cin >> x[i] >> y[i];

  vector<int> p;
  rep(i, n) p.push_back(i);
  double ans = 0;
  do {
    double sum = 0;
    rep(i, n-1) {
      int xl = x[p[i+1]] - x[p[i]];
      int yl = y[p[i+1]] - y[p[i]];
      sum += sqrt(xl * xl + yl * yl);
    }
    ans += sum;
  } while(next_permutation(p.begin(), p.end()));

  int n2 = 1;
  for(int i=1; i<=n; i++) n2 *=i;

  ans /= n2;
  printf("%.10f", ans);
  return 0;
}