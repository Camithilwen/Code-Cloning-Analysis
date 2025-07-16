
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define endl "\n"
#define se second
#define ls( s) (s&(-s))
#define ll long long
#define inf 0x3f3f3f3f
const ll N = 500030;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const ll mod =    998244353;
ll n;
vector<pair<ll,ll> > vp;
ll pre[N],suf[N];
bool comp(pair<ll,ll> p1,pair<ll,ll> p2)
{
	return p1.fi<p2.fi||(p1.fi==p2.fi&&p1.se<p2.se);
}
int main()
{
	ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
   cin>>n;
   for(ll i=0;i<n;i++)
   {
	ll x,y;
	cin>>x>>y;
	vp.emplace_back(x,y);
   }
   sort(vp.begin(),vp.end(),comp);

   ll x1=vp[0].fi;
   ll y1=vp[0].se;
   pre[0]=max(0ll,y1-x1+1);
   for(ll i=1;i<n;i++)
   {
   	x1=max(x1,vp[i].fi);
   	y1=min(y1,vp[i].se);
   	pre[i]=max(0ll,y1-x1+1);
   }
   x1=vp[n-1].fi;
   y1=vp[n-1].se;
   suf[n-1]=max(suf[n-1],y1-x1+1);
   for(ll i=n-2;i>=0;i--)
   {
   	x1=max(x1,vp[i].fi);
   	y1=min(y1,vp[i].se);
   	suf[i]=max(suf[i],y1-x1+1);
   }
   ll ans=0;
   for(ll i=0;i<n-1;i++)
   {
   	if(pre[i]+suf[i+1]>ans)
   	ans=pre[i]+suf[i+1];
  // 	cout<<pre[i]<<" "<<suf[i+1]<<endl;
   }
   ll xx=vp[n-1].fi;

    y1;ll y2;
   ll mn=1e9+6;
   for(int i=0;i<n;i++)
   {
   	if(vp[i].se<mn)
   	{
   		mn=vp[i].se;
   		y1=i;
	   }
   }
   mn=1e9+2;
   for(int i=0;i<n;i++)
   {
   	if(i!=y1)
   	if(vp[i].se<mn)
   	{
   		mn=vp[i].se;
   		y2=i;
	   }
   }
   
	for(ll i=1;i<n-1;i++)
	{
		ll y;
		if(i!=y1)
		y=vp[y1].se;
		else
		y=vp[y2].se;

		ans=max(ans,vp[i].se-vp[i].fi+1+max(0ll,y-xx+1));
	//	cout<<xx<<" "<<y<<endl;
	}
   cout<<ans;
}
