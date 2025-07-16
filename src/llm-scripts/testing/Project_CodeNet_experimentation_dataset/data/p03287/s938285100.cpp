#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll N,M;
  cin>>N>>M;
  vector<ll> mo(N);
  for(ll i = 0LL; i < N; i++) {
    ll x;
    cin>>x;
    if(i==0LL) mo[i]=x%M;
    else mo[i]=(mo[i-1]+x)%M;
  }
  sort(mo.begin(),mo.end());
  ll ans = 0LL;
  ll k = 0LL;
  for(ll i = 0LL; i < N;i++){
    k++;
    if(i==N-1LL||mo[i]!=mo[i+1LL]){
      if(mo[i]==0LL)ans+=(k+k*(k-1LL)/2LL);
      else ans+=(k*(k-1LL)/2LL);
      k=0LL;
    }
  }
  cout<<ans<<endl;
}