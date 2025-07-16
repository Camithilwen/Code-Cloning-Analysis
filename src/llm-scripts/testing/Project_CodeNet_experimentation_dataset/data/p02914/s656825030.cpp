#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int32 n;
  cin >> n;
  vector<int64> a(n);
  REP(i,n)cin >> a[i];
  int64 s = 0;
  REP(i,n)s ^= a[i];
  REP(i,n)a[i] &= ~s;
  // REP(i,n){
  //   cout << bitset<60>(a[i]) << endl;
  // }
  int32 r = 0;
  FORR(d,61,0){
    int32 i;
    for(i = r; i < n; ++i){
      if((a[i]>>d)&1){
        swap(a[r],a[i]);
        break;
      }
    }
    if(i == n)continue;
    REP(j,n){
      if(j == r)continue;
      if((a[j]>>d)&1)a[j] ^= a[r];
    }
    r++;
  }
  // REP(i,n){
  //   cout << bitset<60>(a[i]) << endl;
  // }
  int64 ad = 0;
  REP(i,n)ad ^= a[i];
  ANS(s + (ad << 1));
  return 0;
}