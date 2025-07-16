#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
const int maxn=2e5+7;
const ll modn=1e9+7;
const int inf=2e9+7;
const ll INF=1000000000000000000ll;
const double PI = acos(-1.0);
const double eps=1e-8;
inline int lowbit(int x){return x&-x;}
inline ll lowbit(ll x) {return x&-x;}
inline int CountOneBinary(ll num){int ans=0;while(num){if(num&1) ans+=1;num>>=1;}return ans;}
inline void read(int &x){char c;x=0;for(c=getchar();c>'9'||c<'0';c=getchar());for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';}
inline void read(ll &x){char c;x=0;for(c=getchar();c>'9'||c<'0';c=getchar());for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';}
inline ll qpow(ll x,ll y){ll ans=1;while(y){if(y&1) ans=ans*x%modn;x=x*x%modn;y>>=1;}return ans;}
inline double qpow(double x,ll y){double ans=1;while(y){if(y&1) ans=ans*x;x=x*x;y>>=1;}return ans;}
ll f(ll a,ll b,ll c,ll d)
{
    ll top=max(max(a,b),max(c,d));
    ll bot=min(min(a,b),min(c,d));
    return top-bot;
}
ll n,a[maxn],sum[maxn];
int main()
{
    while(scanf("%lld",&n)==1)
    {
        for(int i=1;i<=n;i++)
        {
             scanf("%lld",&a[i]);
             sum[i]=sum[i-1]+a[i];
        }
        ll ans=INF;
        for(int mid=2;mid<n-1;mid++)
        {
            int m1=upper_bound(sum+1,sum+1+mid,sum[mid]/2)-sum;
            int m2=upper_bound(sum+1+mid,sum+1+n,(sum[n]-sum[mid])/2+sum[mid])-sum;
            ans=min(ans,f(sum[m1],sum[mid]-sum[m1],sum[m2]-sum[mid],sum[n]-sum[m2]));
            ans=min(ans,f(sum[m1-1],sum[mid]-sum[m1-1],sum[m2]-sum[mid],sum[n]-sum[m2]));
            ans=min(ans,f(sum[m1],sum[mid]-sum[m1],sum[m2-1]-sum[mid],sum[n]-sum[m2-1]));
            ans=min(ans,f(sum[m1-1],sum[mid]-sum[m1-1],sum[m2-1]-sum[mid],sum[n]-sum[m2-1]));
        }
        printf("%lld\n",ans);
    }
}
