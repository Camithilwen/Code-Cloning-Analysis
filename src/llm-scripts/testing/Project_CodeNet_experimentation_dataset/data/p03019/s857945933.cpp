#include<bits/stdc++.h>
#define MN 100000
#define ll long long 
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
ll res,v[MN+5],V[MN+5],ans,g[MN+5],G[MN+5];
int n,X,L[MN+5],R[MN+5],b[MN+5],rk[MN+5];
bool cmp(int x,int y){return v[x]+g[x]>v[y]+g[y];}
ll GetV(ll*s,int l,int r,int x){return s[r]-s[l-1]-((x>=l&&x<=r)?s[x]-s[x-1]:0);}
inline int Div(ll x,int y){return (x+y-1)/y;}
int main()
{
    n=read();X=read();
    for(int i=1;i<=n;++i)
    {
        b[i]=read();L[i]=read();R[i]=read();
        v[i]=1LL*(X-b[i])*R[i];g[i]=1LL*b[i]*L[i];
        rk[i]=i;ans+=b[i];
    }
    sort(rk+1,rk+n+1,cmp);
    for(int i=1;i<=n;++i) V[i]=V[i-1]+v[rk[i]],G[i]=G[i-1]+g[rk[i]];
    for(int i=1;i<=n;++i)
    {
        int l=0,r=n-1,mid,res=n;
        while(l<=r)
        {
            mid=l+r>>1;
            ll Val=GetV(V,1,mid,i)-GetV(G,mid+1,n,i)+v[rk[i]];
            if(Val>=0) res=mid,r=mid-1; else l=mid+1;
        }
        ll Val=GetV(V,1,res,i)-GetV(G,res+1,n,i);
        if(Val>=0) ans=min(ans,1LL*(res-(res>=i))*X+max(0,Div(g[rk[i]]-Val,L[rk[i]])));
        else ans=min(ans,1LL*(res-(res>=i))*X+b[rk[i]]+Div(-Val,R[rk[i]]));
    }
    cout<<ans;
	return 0;
}