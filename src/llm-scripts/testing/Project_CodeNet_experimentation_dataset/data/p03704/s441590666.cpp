#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1e5+10;
ll mm,m,n,a[60];
ll f[60];
ll ans;
inline void read(ll &x)
{
	ll f;char c;
	for (f=1,c=getchar();c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for (x=0;c<='9'&&c>='0';c=getchar()) x=x*10+(c&15);x*=f;
}
void dfs(ll x,ll n,ll sum){
    if(x==n/2+1){
        if(sum==m){
           	ll now=a[1]>=0?(9-a[1]):(9+a[1]);
            for(register ll i=2;i<x;i++)
				now*=(a[i]>=0?(10-a[i]):(10+a[i]));
            ans+=n&1?now*10:now;
        }
        return ;
    }
    if(sum+10ll*(f[n-x]-f[x-1])<m||sum-10ll*(f[n-x]-f[x-1])>m)
		return ;
    for(register ll i=-9;i<10;i++){
        a[x]=i;
        dfs(x+1,n,sum+1ll*a[x]*(f[n-x]-f[x-1]));
    }
}
int main(){
    read(m);
	mm=m;f[0]=1;
    while(mm) n++,mm/=10;
    for(register ll i=1;i<=18;i++) f[i]=f[i-1]*10;
    for(register ll i=n;i<=18;i++) dfs(1,i,0);
    printf("%lld\n",ans);
    return 0;
}
