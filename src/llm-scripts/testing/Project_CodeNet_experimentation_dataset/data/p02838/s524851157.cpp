#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long int
#define ull unsigned long long
#define si set <ll>
#define vi vector <ll>
#define popcount(x) __builtin_popcountll(x)
#define mii map <ll,ll>
#define vpi vector <pair <ll,ll> >
#define sz(c) (ll)c.size()
#define fr first
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sc second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define mem0(a) memset(a,0,sizeof(a))
#define rep(i,a,n) for(ll i=a ; i<n ; i++)
#define ld long double
const ll INF = __LONG_LONG_MAX__;
#define rall(a) (a).rbegin(),(a).rend()
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

ll power(ll b,ll e,ll m)
{
  if(b==0) return 0;
  if(e==0) return 1;
  if(e&1) return b*power(b*b%m,e/2,m)%m;
  return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
  if(b==0) return 0;
  if(e==0) return 1;
  if(e&1) return b*power(b*b,e/2);
  return power(b*b,e/2);
}  
bool isPowerOfTwo(ll x)
{
    // x will check if x == 0 and !(x & (x - 1)) will check if x is a power of 2 or not
    return (x && !(x & (x - 1)));
}

ll ans(ll a[],ll n)
{
  ll sum=0;
  for(ll i=0;i<64;i++)
  {
    ll zero=0,one=0;
    for(ll j=0;j<n;j++)
    {
      if(a[j]&1) zero++;
      else one++;
      a[j]/=2;
    }
    ll x=(zero%MOD*one%MOD*power(2,i,MOD))%MOD;
    sum=(sum%MOD+x%MOD)%MOD;
  }
  return sum;
}

void solve()
{
   ll n;
   cin>>n;
   ll a[n];
   rep(i,0,n) cin>>a[i];
   cout<<ans(a,n);
}

int main()
{
  fastio
  ll tt=1;
  // cin>>tt;
  while(tt--)
  {
      solve();
      cout<<"\n";
  }
}