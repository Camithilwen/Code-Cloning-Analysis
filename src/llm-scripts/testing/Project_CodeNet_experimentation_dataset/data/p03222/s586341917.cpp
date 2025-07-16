#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int INT_INF = 1 << 30;
#define MOD 1000000007LL

int main(){
  ll H, W, K;
  cin >> H >> W >> K;

  vll count1(W-1, 0); //count1.at(i)...i~i+1に線があるとき
  vll count2(W, 0); //count2.at(i)...i番目の左右に線がないとき(i-1~i, i~i+1)
  for(int tmp = 0; tmp < (1 << (W-1)); tmp++){
    //1が隣あってないか
    bool ok = true;
    for(int i = 0; i < W-2; i++){
      if((tmp >> i) & (tmp >> (i+1))){
        ok = false;
        break;
      }
    }
    if(!ok) continue;

    for(int i = 0; i < W-1; i++){
      if((tmp >> i) & 1) count1.at(i)++;
    }

    for(int i = 0; i < W; i++){
      bool flag = true;
      if(i > 0){
        if((tmp >> (i-1)) & 1) flag = false; 
      }
      if(i < W-1){
        if((tmp >> i) & 1) flag = false;
      }
      if(flag) count2.at(i)++;
    }
  }

  vvll dp(H+2, vll(W, 0));
  dp.at(1).at(0) = 1;
  for(int i = 2; i < H+2; i++){
    for(int j = 0; j < W; j++){
      if(j > 0) dp.at(i).at(j) += dp.at(i-1).at(j-1) * count1.at(j-1) % MOD;
      dp.at(i).at(j) %= MOD;
      dp.at(i).at(j) += dp.at(i-1).at(j) * count2.at(j) % MOD;
      dp.at(i).at(j) %= MOD;
      if(j < W-1) dp.at(i).at(j) += dp.at(i-1).at(j+1) * count1.at(j) % MOD;
      dp.at(i).at(j) %= MOD;
    }
  }
  cout << dp.at(H+1).at(K-1) << endl;
}