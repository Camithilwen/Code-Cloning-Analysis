#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vec = vector<ll>;
using vecp = vector<P>;
using mat = vector<vec>;
using matp = vector<vecp>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll N,ans=0;
  cin >> N;
  vecp A(N),B(N);
  rep(i,N){
    cin >> B.at(i).first >> B.at(i).second;
  }
  rep(i,N){
    cin >> A.at(i).first >> A.at(i).second;
  }
  sort(all(A));
  sort(all(B));
  set<ll> C;
  ll j=0;
  rep(i,N){
    while(j<N&&B.at(j).first<A.at(i).first){
      C.insert(B.at(j).second);
      j++;
    }
    if(!C.empty()){
      auto a=C.lower_bound(A.at(i).second);
      if(a!=C.begin()){
        a--;
        ans++;
        C.erase(a);
      }
    }
  }
  cout << ans << endl;
    
}