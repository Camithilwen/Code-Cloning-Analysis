#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1, 0);
  for(int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }

  for(int i = 0; i < k; ++i)
  {
    vector<int> next_a(n + 1, 0);
    for(int j = 0; j < n; ++j)
    {
      next_a[ max(0, j - a[j]) ]++;
      next_a[ min(n, j + a[j] + 1) ]--;
    }
    int max_cd_num = 0;
    for(int j = 0; j < n; ++j)
    {
      next_a[j + 1] += next_a[j];
      max_cd_num += (next_a[j] == n);
    }
    a = next_a;
    if (max_cd_num >= n) break;
  }

  for(int i = 0; i < n; ++i) cout << a[i] << " ";


}

int main()
{
  fastio;
  solve();

  return 0;
}