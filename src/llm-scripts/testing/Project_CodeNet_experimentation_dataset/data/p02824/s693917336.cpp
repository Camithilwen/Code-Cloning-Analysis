#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; ll m; cin >> n >> m;
  int v, p; cin >> v >> p;
  map<ll, int> mp;
  vector<ll> A(n);
  rep(i, n) {
    cin >> A[i];
    mp[A[i]]++;
  }
  sort(all(A));
  vector<ll> sum(n+1);
  rep(i, n) sum[i+1] = sum[i] + A[i];
  rrep(i, n) {
    ll margin = 0;
    ll t1 = upper_bound(all(A), A[i]) - begin(A);
    margin += t1 * m;
    ll t2 = upper_bound(all(A), A[i]+m) - begin(A);
    margin += (n-t2) * m;
    if(n-t2 >= p) {
      cout << n - i - 1 << endk;
      return 0;
    }
    ll rem = p - (n-t2);
    ll t3 = upper_bound(all(A), A[i]+m-1) - begin(A);
    margin += (rem-1) * m;
    if((t3-(rem-1)-t1) < 0) continue;
    margin += (A[i]+m) * (t3-(rem-1)-t1) - (sum[t3-(rem-1)]-sum[t1]);
    if(margin >= v * m) continue;
    else {
      cout << n - i - 1 << endk;
      return 0;
    }
  }
  cout << n << endk;
  return 0;
}
