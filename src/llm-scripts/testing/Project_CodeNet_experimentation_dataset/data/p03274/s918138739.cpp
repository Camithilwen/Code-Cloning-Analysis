#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <cmath>

#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;

template<class T> inline bool chmin(T& a,T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if (a < b) {a = b; return true;} return false;}

const ll MOD = 1000000007;
const int INF = 1<<30;
//const ll INF = (ll)1e18 + 1;

int main(){
  int N, K; cin >> N >> K;
  vector<ll> x(N); rep(i, N) cin >> x[i];

  ll ans = INF;
  for (int i = 0; i < N; ++i){
    if (i + K - 1 >= N) continue;
    ll tmp = min(abs(x[i]) + abs(x[i + K - 1] - x[i]), abs(x[i + K - 1]) + abs(x[i + K - 1] - x[i]));
    //cout << x[i] << " " << x[i + K] << endl;
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}
