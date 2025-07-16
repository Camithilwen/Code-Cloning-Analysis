#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  vector<ll> score(n);
  ll ans = 0;
  rep(i, n) {
    cin >> a[i] >> b[i];
    score[i] = a[i] + b[i];
    ans += a[i];
  }
  sort(score.rbegin(), score.rend());

  rep(i, n) {
    if (i % 2) ans -= score[i];
  }
  cout << ans << endl;
}