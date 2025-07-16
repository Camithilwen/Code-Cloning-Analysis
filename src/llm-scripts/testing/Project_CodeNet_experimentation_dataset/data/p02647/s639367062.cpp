#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  ll N,K; cin>>N>>K;
  vector<ll> A(N);
  rep(i,N)
  {
    cin>>A.at(i);
  }
  rep(i,min(K,(ll)100))
  {
    vector<ll> hoge(N,0);
    vector<ll> sirusi(N,0);
    rep(j,N)
    {
      sirusi.at(max((ll)0,j-A.at(j)))++;
      if(j+A.at(j)<N-1)
      {
        sirusi.at(j+A.at(j)+1)--;
      }
    }
    rep(j,N)
    {
      if(j==0) {hoge.at(0)=sirusi.at(0); continue;}
      hoge.at(j)=hoge.at(j-1)+sirusi.at(j);
    }
    A=hoge;
  }
  rep(i,N)
  {
    if(i!=0) {cout<<" ";}
    cout<<A.at(i);
  }
  cout<<endl;
  return 0;
}
