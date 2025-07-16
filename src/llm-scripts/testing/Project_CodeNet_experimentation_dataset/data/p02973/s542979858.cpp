#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
struct edge { ll s, t, x; };
typedef pair<ll, ll> P;
typedef pair<ll,P> event;
const ll MAX = 510000;
const ll MOD = 1000000007;

int main() {
  ll N;
  cin>>N;
  ll A[N];
  rep(i,N){cin>>A[i];A[i]=-1ll*A[i];}
  multiset<ll>ma;
  ma.insert(2ll);
  ma.insert(-100000000000ll);
  ll ans=0ll;
  rep(i,N){
    auto t=ma.upper_bound(A[i]);
    if(*t==2){ma.insert(A[i]);ans++;continue;}
    else{
      ma.erase(t);
      ma.insert(A[i]);
    }
  }
  cout<<ans;
}
