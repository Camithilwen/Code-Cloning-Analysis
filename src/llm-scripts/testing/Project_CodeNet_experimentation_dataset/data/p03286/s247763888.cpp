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

bool ans[60];

int main(){
  ll N; cin >> N;

  for (int i = 0; i < 60; i++){
    ll now = (ll) 1 << (i + 1);
    if (N % now != 0){
      ans[i] = true;
      if (i % 2 == 0) N -= now / 2;
      else N += now / 2;
    }

    if (N == 0){
      for (int j = i; j >= 0; j--) cout << ans[j];
      cout << endl;
      return 0;
    }
  }


  return 0;
}
