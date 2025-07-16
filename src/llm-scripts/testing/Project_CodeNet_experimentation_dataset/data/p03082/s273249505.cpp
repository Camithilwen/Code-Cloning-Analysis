#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 

const int MAX_N = 410;
const int MAX_X = 3e5+10;
const int MOD = 1e9+7;

int dp[MAX_N][MAX_X];
// i番目までで先頭の値がjの時の総和をdp[i][j]をおく

void modadd(int &a, int b ){ 
  a = (a+b)%MOD;
}

signed main(void){ 
  
  int N,X; cin >> N >> X;
  vector<int> s(N);
  map<int,int> mp;
  for(int i = 0; i < N; i++){ cin >> s[i]; }
  
  sort(s.begin(),s.end());
                             
  for(int i = 0; i < MAX_X; i++){ dp[0][i] = i;}  
                            
  
  for(int i = 0; i < N; i++){
    // 次にi+1コメを見る
    for(int x = 0; x < MAX_X; x++){ //先頭の文字全体を探索する
      //未更新から飛ばさない方がいい？
      modadd(dp[i+1][x],dp[i][x%s[i]]);
      modadd(dp[i+1][x],dp[i][x]*i);
    }
  }
      
                     
  cout << dp[N][X] << endl;
  
  return 0;
}
  