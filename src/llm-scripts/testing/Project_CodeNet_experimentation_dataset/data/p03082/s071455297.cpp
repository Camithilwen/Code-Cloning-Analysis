#include <bits/stdc++.h>
using namespace std;
#define REP(i,N) for(i=0;i<N;i++)
typedef long long ll;
typedef pair<int, int> P;
typedef struct{
  int first;
  int second;
  int third;
}T;

//昇順
bool comp_Se(T& l, T& r){
  return l.second < r.second;
}

ll mod =  1e9+7;
int main(void){
  int i,j,N,X;
  cin >> N >> X;
  vector<ll> v(N);
  REP(i,N) cin >> v[i];
  sort(v.begin(),v.end());

  //dp[i][j]:jをXの最初として，i+1回操作(ただしi+1番目まで)を行った時の総和
  ll dp[N][X+1];
  REP(j,X+1){
    dp[0][j] = j%v[0];
  }
  for(i=1;i<N;i++){
    REP(j,X+1){
      //dp[i-1][j%v[i]]:最初に行う場合
      //dp[i-1][j]*i 最初に行わない場合
      dp[i][j] = dp[i-1][j%v[i]] + dp[i-1][j] * i; 
      dp[i][j] %= mod;
    }
  }
  cout << dp[N-1][X] << endl;
  return 0;
}
