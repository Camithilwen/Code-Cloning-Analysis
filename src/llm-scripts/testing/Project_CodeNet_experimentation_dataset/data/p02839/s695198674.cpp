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

#define MAXN 88
#define MAXS 13000

int dp[MAXN][MAXN][MAXS];

int main(){
  int h,w;cin>>h>>w;
  vector<vector<int>> scores(h);
  rep(i, h)rep(j, w){
    int a;cin>>a;
    scores[i].push_back(a);
  }
  rep(i, h)rep(j, w){
    int a;cin>>a;
    scores[i][j] -= a;
    if(scores[i][j] < 0)scores[i][j] *= -1;
  }

  dp[0][0][scores[0][0]] = 1;
  rep(i, h)rep(j, w)rep(k, MAXS){
    int s = scores[i][j];
    int mpre = k-s;
    if(mpre<0)mpre *= -1;
    if(i && dp[i-1][j][mpre]==1)dp[i][j][k]=1;
    if(j && dp[i][j-1][mpre]==1)dp[i][j][k]=1;

    int ppre = k+s;
    if(ppre<=7000){
      if(i && dp[i-1][j][ppre]==1)dp[i][j][k]=1;
      if(j && dp[i][j-1][ppre]==1)dp[i][j][k]=1;
    }
  }

  int result = 0;
  rrep(i, MAXS)if(dp[h-1][w-1][i])result = i;

  cout<<result<<endl;

  return 0;

  rep(i, h){
    rep(j, w)cout<<scores[i][j]<<' ';cout<<endl;
  }
cout<<"###"<<endl;

rep(k, 15){
cout<<k<<endl;
  rep(i, h){
    rep(j, w)cout<<dp[i][j][k]<<' ';cout<<endl;
  }
  cout<<"---"<<endl;
}

  return 0;
}
