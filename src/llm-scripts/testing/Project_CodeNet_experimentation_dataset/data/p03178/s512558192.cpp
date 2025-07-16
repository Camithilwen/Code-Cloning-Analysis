#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

#define MAXN 10000
#define MAXD 100

int dp[MAXN+1][MAXD+1][2];

int main(){
  string s;cin>>s;
  int n = s.size();
//  reverse(s.begin(), s.end());
  int d;cin>>d;

  dp[0][0][1]=1;

  rep(i, n)rep(j, d)rep(k, 10){
    int cd = s[i]-'0';

    int nj = (j+k)%d;

//cout<<cd<<' '<<j<<'>'<<nj<<' '<<k<<endl;

    if(k==cd){
      dp[i+1][nj][1] += dp[i][j][1];
      dp[i+1][nj][0] += dp[i][j][0];
    }else if(k<cd){
      dp[i+1][nj][0] += dp[i][j][1] + dp[i][j][0];
    }else{
      dp[i+1][nj][0] += dp[i][j][0];
    }
    dp[i+1][nj][1] %= MOD;
    dp[i+1][nj][0] %= MOD;
  }

  ll result = (dp[n][0][1]+dp[n][0][0])%MOD;
  cout << (result-1+MOD)%MOD << endl;

  return 0;

cout<<dp[n][0][1]<<' '<<dp[n][0][0]<<endl;
cout<<dp[n][0][1]<<' '<<dp[n][0][0]<<endl;

rep(i, n+1){
  rep(j, d+1)cout<<dp[i][j][0]+dp[i][j][1]<<' ';
  cout<<endl;
}

  return 0;
}

