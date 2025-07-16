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

int H, W, A, B;
bool ans[1005][1005];

int main(){
  cin >> H >> W >> A >> B;

  for (int i = 0; i < B; i++){
    for (int j = 0; j < W; j++){
      if (j < A) cout << 0;
      else cout << 1;
    }
    cout << endl;
  }
  
  for (int i = B; i < H; i++){
    for (int j = 0; j < W; j++){
      if (j < A) cout << 1;
      else cout << 0;
    }
    cout << endl;
  }

  return 0;
}
