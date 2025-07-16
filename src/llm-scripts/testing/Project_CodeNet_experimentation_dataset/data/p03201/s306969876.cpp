#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  vector<lint> A(N);
  REP(i, N) cin >> A[i];
  map<lint, lint> ma;
  REP(i, N) {
    ma[-A[i]]++;
  }
  int ans = 0;
  for(auto itr=ma.begin(); itr!=ma.end(); itr++) {
    lint a = -(itr->first);
    lint b = 1;
    while(b <= a) b *= 2;
    b -= a;
    if(ma.find(-b) != ma.end()) {
      if(a != b && ma[-a] >= 1 && ma[-b] >= 1) {
        int t = min(ma[-a], ma[-b]);
        ma[-a] -= t;
        ma[-b] -= t;
        ans += t;
      } else if(a == b && ma[-a] >= 2){
        int t = ma[-a] / 2;
        ma[-a] -= t*2;
        ans += t;
      }
      
    }
  }
  cout << ans << endl;
}