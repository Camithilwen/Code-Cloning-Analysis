#include<bits/stdc++.h>

const int MOD = 1e9 + 7;

using namespace std;

int main(){
  string K;
  cin >> K;
  
  int D;
  cin >> D;
  
  vector<vector<vector<long long>>> dp(K.size() + 1, vector<vector<long long>>(D, vector<long long>(2, 0)));
  dp[0][0][1] = 1;
  for(int i = 0; i < (int)K.size(); i++){
    for(int j = 0; j < D; j++){
      for(int k = 0; k < 10; k++){
        dp[i + 1][(j + k) % D][0] += dp[i][j][0];
        if(k < K[i] - '0'){
          dp[i + 1][(j + k) % D][0] += dp[i][j][1];
        }else if(k == K[i] - '0'){
          dp[i + 1][(j + k) % D][1] += dp[i][j][1];
        }
        dp[i + 1][(j + k) % D][0] %= MOD;
        dp[i + 1][(j + k) % D][1] %= MOD;
      }
    }
  }
  
  cout << ((dp[K.size()][0][0] + dp[K.size()][0][1] - 1) % MOD + MOD) % MOD << endl;
  
  return 0;
}