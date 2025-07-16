#include <bits/stdc++.h>
 
using namespace std;
 
const long long inf = (long long) 1e18;
 
const int N = 5010;
 
long long f[N][N];
 bool cmp(pair<int,int> a,pair<int,int> b){
return a.first < b.first;
}
int main() {
  int n;
  scanf("%d", &n);
  vector< pair<int,int> > a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a[i].first, &a[i].second);
    a[i].first += a[i].second;
  }
  sort(a.begin(), a.end(),cmp);
  for (int i = 0; i < n; i++) {
    a[i].first -= a[i].second;
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      f[i][j] = inf;
    }
  }
  f[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      long long ft = f[i][j];
      if (ft == inf) {
        continue;
      }
      f[i + 1][j] = min(f[i + 1][j], ft);
      if (ft <= a[i].first) {
        f[i + 1][j + 1] = min(f[i + 1][j + 1], ft + a[i].second);
      }
    }
  }
  int ans = 0;
  for (int j = 0; j <= n; j++) {
    if (f[n][j] != inf) {
      ans = j;
    }
  }
  printf("%d\n", ans);
  return 0;
}