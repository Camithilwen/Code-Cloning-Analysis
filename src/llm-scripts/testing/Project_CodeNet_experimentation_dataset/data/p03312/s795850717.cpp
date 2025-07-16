#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int INF=1e9;
const int MOD=1e9+7;
const double pi=acos(-1);


int main(){
  int n;
  cin >> n;
  vector<ll> s(n+1);
  s[0]=0;
  rep(i,n){
    ll a;
    cin >> a;
    s[i+1]=s[i]+a;
  }
  
  ll ans=1e18;
  ll l=1,r=3;
  for(int i=2;i<n-1;i++){
    if(r<=i)r=i+1;
    while(l+1<i && abs(s[i]-2*s[l+1])<=abs(s[i]-2*s[l])){
      l++;
    }
    while(r+1<n && abs(s[r+1]-s[i]-(s[n]-s[r+1]))<=abs(s[r]-s[i]-(s[n]-s[r]))){
      r++;
    }
    ll M = max({s[l],s[i]-s[l],s[r]-s[i],s[n]-s[r]});
    ll m = min({s[l],s[i]-s[l],s[r]-s[i],s[n]-s[r]});
    ans = min(ans,M-m);
  }
  cout << ans << endl;
}
