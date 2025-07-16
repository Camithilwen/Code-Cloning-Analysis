#include<bits/stdc++.h>
#define title "title"
#define ll long long
#define ull unsigned ll
#define fix(x) fixed<<setprecision(x)
#define pii pair<ll,ll>
#define vint vector<ll>
#define pb push_back
using namespace std;
void Freopen(){
	freopen(title".in","r",stdin);
	freopen(title".out","w",stdout);
}
ll read(){
	ll g=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){g=g*10+ch-'0';ch=getchar();}
	return g*f;
}
const ll N=1e5+5;
ll n,st,x[N],p[N];
ll calc(ll l,ll r,ll t){
	if(st<x[l])return x[r]-st;if(x[r]<st)return st-x[l];
	if(p[l]>=p[r])return p[l]+=p[r],calc(l,r-1,l)+(t==r?x[r]-x[l]:0);
	else return p[r]+=p[l],calc(l+1,r,r)+(t==l?x[r]-x[l]:0);
}
signed main(){
	n=read(),st=read();
	for(ll i=1;i<=n;i++)x[i]=read(),p[i]=read();
	return cout<<calc(1,n,p[1]<p[n]?1:n),signed();
}