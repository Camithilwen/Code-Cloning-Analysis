#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
// #define LOCAL
const ll MOD=998244353;
ll _gcd(ll a,ll b){if(b==0)return a;return _gcd(b,a%b);}
ll gcd(ll a,ll b){a=abs(a),b=abs(b);if(a<b)swap(a,b);return _gcd(a,b);}
ll qpow(ll a,ll n){ll rt=1;while(n){if(n&1)rt=(rt*a)%MOD;a=a*a%MOD;n>>=1;}return rt;}
int N,M,K;
const int MAXN=2e5+10;
ll factor[MAXN];
void init()
{
    factor[0]=1;
    for(int u=1;u<MAXN;u++){
        factor[u]=(factor[u-1]*u)%MOD;
    }
}
ll C(ll n,ll k)
{
    return factor[n]*qpow(factor[n-k],MOD-2)%MOD*qpow(factor[k],MOD-2)%MOD;
}
void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M>>K;
    init();
    ll ans=0;
    for(int u=0;u<=K;u++){
        ans=(ans+M*C(N-1,u)%MOD*qpow(M-1,N-1-u)%MOD)%MOD;
    }
    cout<<ans;
}
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    solve();
}