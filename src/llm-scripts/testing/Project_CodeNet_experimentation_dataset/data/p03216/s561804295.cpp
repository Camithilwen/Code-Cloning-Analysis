//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <time.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
 
const ll inf = 1e9 + 7;
const ll Mod = 998244353;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

int N, Q, K[100];
string S;
ll DP[int(1e6 + 5)][3];

int main(){
  cin >> N >> S >> Q;
  for (int i = 0; i < Q; i++) cin >> K[i];

  for (int i = 0; i < Q; i++){
    DP[0][0] = 0; DP[0][1] = 0; DP[0][2] = 0;
    if (S[0] == 'D') DP[0][0] = 1;
    if (S[0] == 'M') DP[0][1] = 1;

    ll ans = 0;
    for (int j = 1; j < N; j++){
      for (int k = 0; k < 3; k++) DP[j][k] = DP[j - 1][k];

      if (j - K[i] >= 0){
        if (S[j - K[i]] == 'D'){
          DP[j][2] -= DP[j][1];
          DP[j][0]--;
        }
        if (S[j - K[i]] == 'M') DP[j][1]--;
      }

      if (S[j] == 'D') DP[j][0]++;
      if (S[j] == 'M'){
        DP[j][1]++;
        DP[j][2] += DP[j][0];
      }
      if (S[j] == 'C') ans += DP[j][2];
    }
    cout << ans << endl;
  }
  
  return 0;
}
