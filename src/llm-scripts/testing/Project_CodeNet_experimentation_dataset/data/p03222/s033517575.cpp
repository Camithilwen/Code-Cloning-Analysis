#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int H, W, K;
ll DP[101][10]; // 残りn本の段階でiにいる場合の数
ll Memo[9]; // 本数がidxのときに何通りあるか 

void calc() {
  rep(i, H+1) {
    if (i==0) continue;
    rep(j, W) {
      DP[i][j] += DP[i-1][j]*Memo[j]*Memo[W-j-1]; // 左右に棒を置かない
      if (j>0) DP[i][j] += DP[i-1][j-1]*Memo[W-j-1]*Memo[j-1]; // 左に棒を置く
      if (j<W-1) DP[i][j] += DP[i-1][j+1]*Memo[W-j-2]*Memo[j]; // 右に棒を置く
      DP[i][j]%=MOD;
    }
  }
}

int main() {
  INCANT;
  cin >> H >> W >> K;
  if (W==1) {
    cout << 1 << endl;
    return 0;
  }
  Memo[0] = 1;
  Memo[1] = 1;
  rep(i, W) Memo[i+2] = Memo[i]+Memo[i+1];
  DP[0][0] = 1ll;
  calc();
  cout << DP[H][K-1] << "\n";
  return 0;
}
