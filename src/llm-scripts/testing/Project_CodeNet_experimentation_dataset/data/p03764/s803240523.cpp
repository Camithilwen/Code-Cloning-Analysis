#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main()
{
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int n, m;
  cin >> n >> m;
  int a[n];
  int b[m];
  for(int i = 0;i < n;i++)
    cin >> a[i];
  for(int i = 0;i < m;i++)
    cin >> b[i];
  long long x_sum = 0, y_sum = 0;
  for(int i = 0;i < n - 1;i++){
    x_sum += 1ll * (i + 1) * (n - i - 1) % MOD * (a[i + 1] - a[i]) % MOD;
    if(x_sum >= MOD)
      x_sum -= MOD;
  }
  for(int i = 0;i < m - 1;i++){
    y_sum += 1ll * (i + 1) * (m - i - 1) % MOD * (b[i + 1] - b[i]) % MOD;
    if(y_sum >= MOD)
      y_sum -= MOD;
  }
  cout << x_sum * y_sum % MOD;
}
