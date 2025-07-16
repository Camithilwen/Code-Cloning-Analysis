#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
const int maxn=2e5+7;
const ll modn=1e9+7;
const int inf=2e9+7;
const double PI = acos(-1.0);
const double eps=1e-8;
inline int lowbit(int x){return x&-x;}
inline ll lowbit(ll x) {return x&-x;}
inline int CountOneBinary(ll num){int ans=0;while(num){if(num&1) ans+=1;num>>=1;}return ans;}
inline void read(int &x){char c;x=0;for(c=getchar();c>'9'||c<'0';c=getchar());for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';}
inline void read(ll &x){char c;x=0;for(c=getchar();c>'9'||c<'0';c=getchar());for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';}
inline ll qpow(ll x,ll y){ll ans=1;while(y){if(y&1) ans=ans*x%modn;x=x*x%modn;y>>=1;}return ans;}
inline double qpow(double x,ll y){double ans=1;while(y){if(y&1) ans=ans*x;x=x*x;y>>=1;}return ans;}
ll inv[maxn],h,w,a,b;
inline ll C(ll x,ll y)
{
    x=min(x,y-x);
    ll ans=1;
    for(ll up=y,down=1;down<=x;down++,up--) ans=ans*up%modn*inv[down]%modn;
    return ans;
}
int main()
{
    for(ll i=1;i<maxn;i++) inv[i]=qpow(i,modn-2);
    while(scanf("%lld%lld%lld%lld",&h,&w,&a,&b)==4)
    {
        ll ans=C(h-1,w+h-2);
        ll left=C(w-b-1,a+w-b-2),right=C(b-1,h-a+b-1);
        while(a)
        {
            ans=((ans-left*right%modn)%modn+modn)%modn;
            left=left*(a-1)%modn*inv[a+w-b-2]%modn;
            right=right*(h-a+b)%modn*inv[h-a+1]%modn;
            a--;
        }
        printf("%lld\n",ans);
    }
}
