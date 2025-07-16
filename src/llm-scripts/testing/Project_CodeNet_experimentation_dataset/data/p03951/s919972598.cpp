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

int main(){
  int N; string S, T;
  cin >> N >> S >> T;

  for (int i = 0; i < N; i++){
    string ans = "";
    for (int j = 0; j < i; j++) ans += S[j];
    for (int j = 0; j < N; j++) ans += T[j];

    bool flag = true;
    for (int j = 0; j < N; j++){
      if (ans[j] != S[j]) flag = false;
    }
    if (flag){
      cout << ans.length() << endl;
      return 0;
    }
  }
  cout << N * 2 << endl;

  return 0;
}
