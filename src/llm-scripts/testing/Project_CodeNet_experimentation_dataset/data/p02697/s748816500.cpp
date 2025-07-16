#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;
const ll INF = 1LL<<60;
const ll mod = 998244353;

int main()
{
  int n, m; cin>>n>>m;

  bool flg = false;
  for (int i=1; i<=m; i++) {
    int l = i;
    int r = n-i;
    if (n%2 == 0 && !flg && r-l <= n/2) flg = true;
    if (flg) r--;
    printf("%d %d\n", l, r);
  }

  return 0;
}
