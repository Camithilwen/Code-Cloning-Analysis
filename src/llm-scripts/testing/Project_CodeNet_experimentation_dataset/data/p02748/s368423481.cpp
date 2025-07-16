#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main(){
  ll A,B,M; cin>>A>>B>>M;
  vector<ll> a(A),b(B);
  ll mina=INF,minb=INF;
  rep(i,A) {cin>>a.at(i); chmin(mina,a.at(i));}
  rep(i,B) {cin>>b.at(i); chmin(minb,b.at(i));}
  
  ll ans=mina+minb;
  rep(i,M){
    ll x,y,c; cin>>x>>y>>c; x--; y--;
    ll sum=a.at(x)+b.at(y)-c;
    chmin(ans,sum);
  }
  
  cout<<ans<<endl;
  return 0;
}
