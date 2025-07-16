#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;

int main() {
  int n, k;
  cin >> n >> k;
  vector<double> mean(n);
  rep(i,n)  {
    double p; cin >> p;
    double m = (p+1) / 2;
    mean[i] = m;
  }
  double ans = 0;
  rep(i,k) ans += mean[i];
  double  r = ans;
  //rep(i,n) cout << mean[i] << ' ' ;
  for (int i = k; i < n; i++)
  {
    double now = r - mean[i-k] + mean[i];
    r = now;
    ans = max(ans, now);
  }
  
  cout << fixed << setprecision(10);
  cout << ans << endl;
  return 0;
}