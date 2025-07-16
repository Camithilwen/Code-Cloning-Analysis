#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
/*
5の数
2の数
mapでいれとく
{2,5,小数の数｝

7.5=0,3,1
2.4=3,0,1
3-2=1>0だからOK
全部9桁として
9+4=13桁として扱う
2と5が18桁あればOK

10.000
20.000

10*10の組み合わせもとっちゃう。
2
200000*400はぎりぎりせーふ。50msくらい。
200000*1になりそう
*/
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  ll N; cin>>N;
  vector<vector<ll>> DP(20, vector<ll>(20,0));
  vector<pair<ll,ll>> Z(N,{0,0});
  rep(i,N){
    string S; cin>>S;
    ll n=0, j=0, d=100;
    while (S[j] && d-->0){
      if (S[j] == '.'){
        d=9;
        j++;
        continue;
      }
      n = n * 10 + (S[j++] - '0');
    }
    
    d = min(d, 9LL);
    ll two=d, five=d;
    while (n%2==0){
      two++;
      n/=2;
    }
    while (n%5==0){
      five++;
      n/=5;
    }
    two = min(two,18LL);
    five = min(five,18LL);
    DP[two][five]++;
    Z[i] = {two,five};
  }
//DPつくる
  for(ll j=18; j>=0; j--) for(ll k=18; k>=0; k--)
    DP[j][k] += DP[j][k+1];
  for(ll j=18; j>=0; j--) for(ll k=18; k>=0; k--)
    DP[k][j] += DP[k+1][j];

  ll ans=0;
  rep(i, N){
    ll t=Z[i].first;
    ll f=Z[i].second;
    ans += DP[18-t][18-f];
    if (t>=9 && f>=9)
      ans--;
  }
  ans /= 2;
  cout<<ans<<endl;
}
