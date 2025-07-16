#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  ll n,Y; cin >> n >> Y;
  ll sum;
  REP(i,n+1){
    REP(j,n-i+1){
      int k = n - i - j;
      sum = 10000 * i + 5000 * j + 1000 * k;
      if(sum == Y){
        printf("%d %d %d",i,j,k);
        return 0;
      }
    }
  }
  printf("-1 -1 -1");
}