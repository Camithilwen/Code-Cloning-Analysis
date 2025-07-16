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
  string S; cin >> S;
  int N = S.length();

  for (int i = 1; i < N; i++){
    if (S[i-1] == S[i]){
      cout << i << " " << i+1 << endl;
      return 0;
    }
  }

  for (int i = 2; i < N; i++){
    if (S[i-2] == S[i]){
      cout << i-1 << " " << i+1 << endl;
      return 0;
    }
  }
  cout << -1 << " " << -1 << endl;

  return 0;
}
