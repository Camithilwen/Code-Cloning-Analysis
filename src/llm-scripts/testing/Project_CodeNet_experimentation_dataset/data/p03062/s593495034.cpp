#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout <<(#x)<<" is "<<(x)<<endl
#define debug cout <<"hi"<<endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int MOD=1e9+7;
const int INF32=1<<30;
const ll INF64=1LL<<60;

void solve(){
  int n; cin >>n;
  ll a[n],cnt=0,sum=0,mn=MOD;
  for(int i=0; i<n; i++){
    ll x; cin >>x; a[i]=x;
    if(x<=0) cnt++;
    mn=min(mn,abs(x));
    sum+=abs(x);
  }
  if(cnt%2) sum-=2*mn;
  cout <<sum;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  solve();
return 0;}