#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

ll N, K, ans = 1e18;

int Solve(ll num, ll turn){
  if (turn == N){
    ans = min(ans, num);
    return 0;
  }

  Solve(num * 2, turn + 1);
  Solve(num + K, turn + 1);
  return 0;
}

int main(){
  cin >> N >> K;
  Solve(1, 0);
  cout << ans << endl;

  return 0;
}
