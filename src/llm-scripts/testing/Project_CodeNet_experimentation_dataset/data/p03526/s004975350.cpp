#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#define vll vector<ll>
#define vvvl vector<vvl>
#define vvl vector<vector<ll>>
#define VV(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define VVV(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;

ll INF = 1000000000;
int main(int argc, char const *argv[]) {
  ll n;std::cin >> n;
  vvl dat = VV(n, 2, 0, ll);
  re(i, n) {
    scanf("%lld %lld", &dat[i][0], &dat[i][1]);
    dat[i][0] = INF - dat[i][0];
  }
  sort(all(dat), [](vll a, vll b){return a[0]-a[1]>b[0]-b[1];});

  vvl dp = VV(n+1, n+1, -INF*INF, ll);
  dp[0][0] = INF;

  for(int i=1;i<=n;i++){
    dp[i][0] = INF;
    for(int j=1;j<=i;j++){
      if(dp[i-1][j-1]<dat[i-1][0]) dp[i][j] = dp[i-1][j];
      else dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]-dat[i-1][1]);
    }
  }
  ll ans = 0;
  for(int i=0;i<=n;i++) if(dp[n][i]!=-INF*INF) ans = i;
  std::cout << ans << '\n';
  return 0;
}
