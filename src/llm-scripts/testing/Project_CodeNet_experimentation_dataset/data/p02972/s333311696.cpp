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

int N, A[int(2e5+5)], ans[int(2e5+5)];
vector <int> res;

int main(){
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];

  for (int i = N; i >= 1; i--){
    if (ans[i] % 2 == A[i]) continue;
    res.push_back(i);
    for (int j = 1; j * j <= i; j++){
      if (i % j != 0) continue;
      ans[j]++;
      if (j * j != i) ans[i/j]++;
    }
  }

  for (int i = 1; i <= N; i++){
    if (ans[i] % 2 != A[i]){
      cout << -1 << endl;
      return 0;
    }
  }

  int M = res.size();
  cout << M << endl;
  for (int i = 0; i < M; i++){
    cout << res[i];
    if (i < M - 1) cout << " ";
    else cout << endl;
  }

  return 0;
}
