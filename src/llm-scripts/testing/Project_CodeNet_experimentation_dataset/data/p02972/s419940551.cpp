#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

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

int N, A[int(2e5+5)], now[int(2e5+5)];
vector <int> ans;

int main(){
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];

  for (int i = N; i >= 1; i--){
    if (now[i] % 2 == A[i]) continue;
    ans.push_back(i);
    for (int j = 1; j * j <= i; j++){
      if (i % j != 0) continue;
      now[j]++;
      if (j * j != i) now[i/j]++;
    }
  }

  if (now[1] % 2 != A[1]){
    cout << -1 << endl;
    return 0;
  }

  int M = ans.size();
  cout << M << endl;
  if (M > 0){
    cout << ans[0];
    for (int i = 1; i < M; i++) cout << " " << ans[i];
    cout << endl;
  }

  return 0;
}
